
#ifndef _DUMMY_FILE_H_
#define _DUMMY_FILE_H_

__BEGIN_DECLS

#include <yaul.h>
#include "block.h"

#define DEBUG_PRINT 1

#define FILE int

void initFileSystem();
CDFileHandle GetDoomWad();
CDFileHandle GetDoom2Wad();

#pragma GCC diagnostic ignored "-Wunused-parameter"
static inline FILE* __always_inline 
fopen(char const* _FileName, char const* _Mode)
{
    return NULL;
}

static inline int __always_inline 
fprintf(FILE* const _Stream, char const* const _Format, ...)
{
    return 0;
}

static inline int __always_inline 
fclose(FILE* _Stream)
{
    return 0;
}

#if DEBUG_PRINT == 1
void getinput();
void clearscreen();
#endif
#pragma GCC diagnostic pop // "-Wunused-parameter"

__END_DECLS

#endif /* !_DUMMY_FILE_H_ */