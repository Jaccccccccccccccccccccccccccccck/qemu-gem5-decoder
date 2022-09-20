#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

typedef struct {
    uint32_t size;
    volatile uint32_t index_r;
    volatile uint32_t index_w;
    uint32_t item_size;
    int shm_id;
} ring_buf_t;

ring_buf_t* ring_buf_shm_malloc(key_t key, size_t item_size, size_t item_num);
// int ring_buf_init(ring_buf_t* ring_buf);
int ring_buf_in(ring_buf_t* ring_buf, void* item);
int ring_buf_out(ring_buf_t* ring_buf);
// rm shm ring buffer by key, 1 for success, 0 for fail
int ring_buf_rm(ring_buf_t *ring_buf);

static inline uint32_t ring_buf_len(ring_buf_t* ring_buf) {
    return ring_buf->index_w - ring_buf->index_r;
}

static inline uint32_t ring_buf_is_empty(ring_buf_t* ring_buf) {
    return ring_buf->index_w == ring_buf->index_r;
}

static inline uint32_t ring_buf_cur_size(ring_buf_t* ring_buf) {
    return (ring_buf->index_w + ring_buf->size - ring_buf->index_r) % ring_buf->size;
}

static inline uint32_t ring_buf_is_full(ring_buf_t* ring_buf) {
    return (ring_buf->index_w + ring_buf->size - ring_buf->index_r) % ring_buf->size == ring_buf->size - 1;
}

static inline void* sing_buf_get_cur_write_addr(ring_buf_t* ring_buf) {
    return (void*)(ring_buf + sizeof(ring_buf_t) + ring_buf->index_w * ring_buf->item_size);
}

static inline void ring_buf_print_status(ring_buf_t* ring_buf) {
    printf("ring_buf size: %d, used size: %d, index_r: %d, index_w: %d\n", ring_buf->size, ring_buf_cur_size(ring_buf), ring_buf->index_r, ring_buf->index_w);
}

#endif /* RING_BUFFER_H */