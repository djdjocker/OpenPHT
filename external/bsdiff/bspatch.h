#ifndef __BSPATCH_H__
#define __BSPATCH_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct bspatch_stream
{
  void* opaque;
  int (*read)(const struct bspatch_stream* stream, void* buffer, int length);
};

int bspatch(const uint8_t* old, int64_t oldsize, uint8_t* newdata, int64_t newsize,
            struct bspatch_stream* stream);
int bspatch_files(const char* oldFile, const char* newFile, const char* patchFile);

#ifdef __cplusplus
}
#endif

#endif
