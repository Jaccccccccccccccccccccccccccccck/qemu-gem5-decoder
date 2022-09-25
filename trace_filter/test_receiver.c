#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#include "ring_buf.h"
#include "shm.h"
#include "trace_filter.h"

int main(int argc, char** argv) {
    ring_buf_t* ring_buf_by_cpu[1024];
    // get arg -n, cpu number
    int cpu_num = 0;
    int ch;
    while ((ch = getopt(argc, argv, "n:")) != -1) {
        switch (ch) {
            case 'n':
                cpu_num = atoi(optarg);
                break;
            default:
                break;
        }
    }
    if (!cpu_num) {
        printf("need a -n arg, means cpu number!\n");
        exit(1);
    }

    // init shm connect
    if (!get_shm_user_base()) {
        if (shm_init(NULL, "/tmp/1")) {
            printf("init shm done\n");
        } else {
            printf("init share mem error!\n");
            exit(0);
        }
    }

    key_t shm_key = ftok("/dev/null", 0);
    if (shm_key == -1) {
        perror("ftok error");
        exit(1);
    }
    printf("get key: %x\n", shm_key);
    for (int i = 0; i < cpu_num; i++) {
        int shm_id = shmget(shm_key + i, 0, 0644 | IPC_CREAT);
        ring_buf_by_cpu[i] = (ring_buf_t*)shmat(shm_id, NULL, 0);
        printf("get cpu %d ring buffer by key: %x\n", i, shm_key + i);
    }

    // get trace from shm
    tb_info_t* tb_info = init_new_tb_info();
    uint64_t user_inst_count = 0;
    uint64_t sys_inst_count = 0;
    while (1) {
        for (int i = 0; i < cpu_num; i++) {
            while (ring_buf_out(ring_buf_by_cpu[i], tb_info)) {
                if (!tb_info->insn_type) {
                    print_trace(tb_info);
                }
                user_inst_count += tb_info->insn_type ? 0 : tb_info->real_insn_num;
                sys_inst_count += tb_info->insn_type ? tb_info->real_insn_num : 0;
            }
        }
        if (ring_buf_by_cpu[0]->trace_end) {
            for (int i = 0; i < cpu_num; i++) {
                while (ring_buf_out(ring_buf_by_cpu[i], tb_info)) {
                    if (!tb_info->insn_type) {
                        print_trace(tb_info);
                    }
                    user_inst_count += tb_info->insn_type ? 0 : tb_info->real_insn_num;
                    sys_inst_count += tb_info->insn_type ? tb_info->real_insn_num : 0;
                }
            }
            break;
        }
    }
    printf("user inst count: %ld\n", user_inst_count);
    printf("sys inst count: %ld\n", sys_inst_count);
}
