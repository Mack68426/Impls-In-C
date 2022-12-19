#ifndef _BASIS_H_
#define _BASIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define container_of(ptr, type, member)					\
	({								\
		const typeof(((type *)0)->member ) *__mptr = (ptr);	\
		(type *)((char *)__mptr - offsetof(type,member));	\
	})


#define new(TYPE, args...) TYPE ## _construct(malloc(sizeof(TYPE)), ## args)
#define delete(TYPE, ptr) do { TYPE ## _destruct(ptr); free(ptr); } while(0)

#define new$(TYPE, args...) $ ## TYPE(malloc(sizeof(TYPE)), ## args)
#define delete$(TYPE, ptr) do { $X ## TYPE(ptr); free(ptr); } while(0)

#define allocate(ptr, size)  if( !( (ptr) = (typeof(ptr))malloc(size)) ) {  perror("Allocation Failed\n"); exit(0);} return ptr;
#define release(ptr) { free(ptr) };

#endif