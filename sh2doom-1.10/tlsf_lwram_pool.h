
#pragma once

void init_tlsf_lwram(void);

void* lwram_malloc(size_t n);
void* lwram_realloc(void* old, size_t new_len);
void* lwram_memalign(size_t n, size_t align);
void lwram_free(void* addr);