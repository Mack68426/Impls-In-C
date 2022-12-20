#ifndef _BASIS_H_
#define _BASIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// ooc 
#define container_of(ptr, type, member)					\
	({								\
		const typeof(((type *)0)->member ) *__mptr = (ptr);	\
		(type *)((char *)__mptr - offsetof(type,member));	\
	})


#define new(TYPE, args...) TYPE ## _construct(malloc(sizeof(TYPE)), ## args)
#define delete(TYPE, ptr) do { TYPE ## _destruct(ptr); free(ptr); } while(0)

// conbined ideas 
#define new$(TYPE, args...) $ ## TYPE(malloc(sizeof(TYPE)), ## args)
#define delete$(TYPE, ptr) do { $X ## TYPE(ptr); free(ptr); } while(0)
#define printfit(T, format, args...) T ## _printf(format, ## args)

// Old Ideas
#define allocate(ptr, s)	((!( (ptr) = (typeof(ptr)) malloc(s)) ) ? &perror("Allocation Failed\n") : ptr)
#define collect(ptr) free(ptr)

#endif