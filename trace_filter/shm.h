#ifndef __SHM_H__
#define __SHM_H__
/*
a modified header version of https://github.com/MihirLuthra/shm_alloc
*/
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef unsigned long shm_offt;

int shm_init(void*, char* shm_filename);
void shm_deinit(void);
void* get_shm_user_base(void);
shm_offt shm_malloc(size_t size);
void shm_free(shm_offt shm_ptr);

#define SHM_OFFT_TO_ADDR(offset) ((void*)((uint8_t*)get_shm_user_base() + offset))
#define SHM_ADDR_TO_OFFT(address) ((shm_offt)((uint8_t*)address - (uint8_t*)get_shm_user_base()))
#define SHM_NULL ((shm_offt)0)

#endif /* __SHM_H__ */
