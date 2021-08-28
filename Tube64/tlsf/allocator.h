#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#if defined(__cplusplus)
extern "C" {
#endif

extern char *HEAP_MEMORY;
extern uintptr_t BASE64;

void Allocator_Init(void);
void Allocator_DeInit(void);

void *Malloc(size_t size);
void Free(void *ptr);
void *Calloc(size_t num,size_t size);
void *Realloc(void *ptr,size_t newsize);

#if defined(__cplusplus)
};
#endif

#endif
