
#ifndef _DUMMY_FILE_H_
#define _DUMMY_FILE_H_

__BEGIN_DECLS

#include <yaul.h>
#include "block.h"

#define DEBUG_PRINT 1
#define DEBUG_PHASE_1 0
#define DEBUG_PHASE_2 0
#define DEBUG_PHASE_3 1

#define FILE int

void initFileSystem();
CDFileHandle GetDoomWad();
CDFileHandle GetDoom2Wad();

static inline FILE* __always_inline 
fopen(char const* _FileName __unused, char const* _Mode __unused)
{
    assert(false);
    return NULL;
}

static inline int __always_inline 
fprintf(FILE* const _Stream __unused, char const* const _Format __unused, ...)
{
    assert(false);
    return 0;
}

static inline int __always_inline 
fclose(FILE* _Stream __unused)
{
    assert(false);
    return 0;
}

int debug_phase1(const char * __restrict fmt, ...);
int debug_phase2(const char * __restrict fmt, ...);
int debug_phase3(const char * __restrict fmt, ...);

#if DEBUG_PRINT == 1
void getinput();
void clearscreen();
#endif

__END_DECLS

#endif /* !_DUMMY_FILE_H_ */