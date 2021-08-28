#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <malloc.h>

#include "tlsf.h"

#include "allocator.h"

#define HEAP_MEMORY_SIZE 0x400000 /* 4 MB */

char *HEAP_MEMORY=NULL;

uintptr_t BASE64;

tlsf_t tlsf=NULL;

void Allocator_Init(void)
{
 #ifdef __linux__

 HEAP_MEMORY=(char*)memalign(HEAP_MEMORY_SIZE,HEAP_MEMORY_SIZE);

 #else

 HEAP_MEMORY=(char*)__mingw_aligned_malloc(HEAP_MEMORY_SIZE,HEAP_MEMORY_SIZE);

 #endif

 BASE64=((uintptr_t)HEAP_MEMORY)&0xFFFFFFFF00000000;

 memset(HEAP_MEMORY,0,HEAP_MEMORY_SIZE);

 tlsf=tlsf_create_with_pool((void*)HEAP_MEMORY,HEAP_MEMORY_SIZE);
}

void Allocator_DeInit(void)
{
 #ifdef __linux__

 free(HEAP_MEMORY);

 #else

 __mingw_aligned_free(HEAP_MEMORY);

 #endif
}

void *Malloc(size_t size)
{
// printf("===> malloc\n");
 if(!size)
 {
  return NULL;
 }

 return tlsf_malloc(tlsf,size);
}

void Free(void *ptr)
{
// printf("===> free\n");
 if(ptr)tlsf_free(tlsf,ptr);
}

void *Calloc(size_t num,size_t size)
{
 size_t ns=num*size;
 void *r=Malloc(ns);
 if(r)memset(r,0,ns);
 return r;
}

void *Realloc(void *ptr,size_t newsize)
{
 return tlsf_realloc(tlsf,ptr,newsize);
}

