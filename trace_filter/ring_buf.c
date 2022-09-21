#include "trace_filter/ring_buf.h"
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

ring_buf_t* ring_buf_shm_malloc(key_t key, size_t item_size, size_t item_num) {
    int shm_id = shmget(key, sizeof(ring_buf_t) + item_num * item_size, 0644 | IPC_CREAT);
    if (shm_id == -1) {
        return NULL;
    }
    ring_buf_t* ring_buf = (ring_buf_t*)shmat(shm_id, NULL, 0);
    if (ring_buf == (void*)-1) {
        return NULL;
    }
    ring_buf->index_r = 0;
    ring_buf->index_w = 0;
    ring_buf->size = item_num;
    ring_buf->item_size = item_size;
    ring_buf->shm_id = shm_id;
    return ring_buf;
}

int ring_buf_in(ring_buf_t* ring_buf, void* item) {
    if (!ring_buf_is_full(ring_buf)) {
        memcpy(sing_buf_get_cur_write_addr(ring_buf), item, ring_buf->item_size);
        ring_buf->index_w = (ring_buf->index_w + 1) % ring_buf->size;
        return 1;
    }
    return 0;
}

int ring_buf_out(ring_buf_t* ring_buf) {
    if (!ring_buf_is_empty(ring_buf)) {
        sing_buf_get_cur_write_addr(ring_buf);
        ring_buf->index_r = (ring_buf->index_r + 1) % ring_buf->size;
        return 1;
    }
    return 0;
}

int ring_buf_rm(ring_buf_t* ring_buf) {
    return shmctl(ring_buf->shm_id, IPC_RMID, NULL) != -1; // -1 means rm shmid error
}

// void main() {
//     int ring_buf_size = 5;
//     int insert_count = 10;
//     int out_count = 7;
//     key_t shm_key = ftok("/dev/null", 0);
//     printf("get shm key:%d\n", shm_key);
//     ring_buf_t* ring_buf = ring_buf_shm_malloc(shm_key, 8, ring_buf_size);
//     printf("init a ring buff size = %d\n", ring_buf_size);
//     for (int i = 0; i < insert_count; i++) {
//         void* a = (void*)malloc(8);
//         if (ring_buf_in(ring_buf, a)) {
//             printf("insert %d success\n", i);
//         } else {
//             printf("insert %d fail\n", i);
//         }
//         ring_buf_print_status(ring_buf);
//     }
//     for (int i = 0; i < out_count; i++) {
//         if (ring_buf_out(ring_buf)) {
//             printf("out %d success\n", i);
//         } else {
//             printf("out %d fail\n", i);
//         }
//         ring_buf_print_status(ring_buf);
//     }
//     if (ring_buf_rm(ring_buf)) {
//         printf("shm ring buf remove!\n");
//     } else {
//         printf("error shm ring buf remove!\n");
//     }
//     return;
// }