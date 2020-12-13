
#include <yaul.h>
#include "mm/tlsf.h"
#include "tlsf_lwram_pool.h"

#define TLSF_LWRAM_POOL_START    (LWRAM(0))
#define TLSF_LWRAM_POOL_SIZE     LWRAM_SIZE

static tlsf_t lwram_pool;

void init_tlsf_lwram(void)
{
    lwram_pool = tlsf_create_with_pool((void *)TLSF_LWRAM_POOL_START, TLSF_LWRAM_POOL_SIZE);
}

void* lwram_malloc(size_t n)
{
    void *ret;
    ret = tlsf_malloc(lwram_pool, n);

    return ret;
}

void* lwram_realloc(void* old, size_t new_len)
{
    void *ret;
    ret = tlsf_realloc(lwram_pool, old, new_len);

    return ret;
}

void* lwram_memalign(size_t n, size_t align)
{
    void *ret;
    ret = tlsf_memalign(lwram_pool, n, align);

    return ret;
}

void lwram_free(void* addr)
{
    tlsf_free(lwram_pool, addr);
}
