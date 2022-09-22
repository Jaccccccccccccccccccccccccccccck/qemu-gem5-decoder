#ifndef TRACE_FILTER_H
#define TRACE_FILTER_H
#include <stdio.h>
#include <glib.h>
#include <stdbool.h>

struct TraceFilter {
    bool is_filter_on;
    bool is_filter_by_pid;
    int pid; // pid to trace
    GHashTable *is_pid_on_trace_list;
};

#define MEM_LOAD	(0x1)
#define	MEM_STORE	(0x2)

struct mem_info {
    unsigned long addr;
    unsigned int type;
};
typedef struct mem_info mem_info_t;

#define MAX_MEMINFOS 1100

struct tb_info {
    int real_insn_num;
    int cpu_id;
    int insn_type; /* tb_insn's mode,system = 1,user = 0 */
    unsigned int pid;
    unsigned int tgid;
    unsigned long current;
    unsigned long offset;
    int mem_num;
    struct mem_info mi[MAX_MEMINFOS];
};
typedef struct tb_info tb_info_t;

struct inst_info {
    unsigned long pc;
    unsigned int instr;
    unsigned long hva;
};
typedef struct inst_info inst_info_t;

struct tb_inst_info {
    int insn_num;
    unsigned long pc_start; /* tb first pc */
    struct inst_info ti[512];
};
typedef struct tb_inst_info tb_inst_info_t;

static inline void print_tb_info(tb_info_t* tb_info) {
    printf("cpu: %d, el_type: %d, pid: %d, tgid:%d, inst num:%d\n", tb_info->cpu_id, tb_info->insn_type, tb_info->pid, tb_info->tgid, tb_info->real_insn_num);
}

static inline void printTrace(tb_info_t* tb_info, tb_inst_info_t* tb_inst_info) {
    printf("cpu: %d, pid: %d, tgid:%d, inst num:%d\n", tb_info->cpu_id, tb_info->pid, tb_info->tgid, tb_info->real_insn_num);
    for(int i = 0; i < tb_inst_info->insn_num; i++) {
        printf("%lx %x\n", tb_inst_info->ti[i].pc, tb_inst_info->ti[i].instr);
    }
    printf("\n");
}

static inline tb_info_t* init_new_tb_info(void) {
    tb_info_t* tb_info = malloc(sizeof(tb_info_t));
    tb_info->real_insn_num = 0;
    tb_info->cpu_id = 0;
    tb_info->insn_type = 0; /* tb_insn's mode,system = 1,user = 0 */
    tb_info->pid = 0;
    tb_info->tgid = 0;
    tb_info->current = 0;
    tb_info->offset = 0;
    tb_info->mem_num = 0;
    return tb_info;
}

static inline void reset_tb_info(tb_info_t* tb_info) {
    tb_info->real_insn_num = 0;
    tb_info->cpu_id = 0;
    tb_info->insn_type = 0; /* tb_insn's mode,system = 1,user = 0 */
    tb_info->pid = 0;
    tb_info->tgid = 0;
    tb_info->current = 0;
    tb_info->offset = 0;
    tb_info->mem_num = 0;
}

#endif /* TRACE_FILTER_H */