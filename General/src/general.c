/* not done yet */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

#include "lib\core\basis.h"
#include "lib\core\types.h"
#include "object.h"
#include "general.h"

// #define __allocate(ptr, size) { if( !( (ptr) = (typeof(ptr))malloc(size)) ) {  perror("Allocation Failed\n"); exit(0);} return ptr;}
// #define __release(ptr) { free(ptr) }
// #define __new(name, var) { (typeof(name) *) p = __allocate(name, sizeof(name)); ; return (p = var);}

static int General_equals(Object*, Object*);
static void General_collect(Object*);
static Object *General_duplicate(Object*);
static DataType General_getType(Object*);


static int *General_compare(void*, void*);

inline int vasprintf(char** buffer, const char* format, va_list ap);
inline int asprintf(char** buffer, const char* format, ...);

General *General_construct(void* addr)
{
    if (!addr)  return NULL;
    General* obj = addr;

    /*   成員函式綁定   */
    obj->equals    = General_equals;
    obj->collect   = General_collect;
    obj->duplicate = General_duplicate;
    obj->getType   = General_getType;
    obj->compare   = General_compare;

    return obj;
}

void General_destruct(General* self)
{

}

int General_equals(Object* self, Object* other)
{
    General* obj1 = container_of(self, General, iobj);
    General* obj2 = container_of(other, General, iobj);
    
    

    return obj1->type == obj2->type && Primitives_compare(&obj1->value, &obj2->value);
}

void General_collect(Object* self)
{
    General* object = container_of(self, General, iobj);

    free(object);
}

General* General_duplicate(General* self)
{
    General* other = self;

    return other;
}


int General_compare(void* self, void* other)
{
    assert(self  != NULL);
    assert(other != NULL);

    General* obj1 = container_of( (Object* )self,  General, iobj);
    General* obj2 = container_of( (Object* )other, General, iobj);

    Primitive value1 = ((General *)self)->value;
    Primitive value2 = ((General *)other)->value;

    

}

void General_printf(const char* fmt)
{
    General* obj;
    if (strcmp(fmt, "%$") != 0) perror("Error: Unsupported pattern\n");

    else    printf("");
}


int vasprintf(char** buffer, const char* format, va_list ap)
{   
    // vsnprintf 為將va_list中的內容寫道字串中，並且限制字串長度
    // 第一次的 NULL 只是為了要算字串長度而不是為了寫入

    int length = vsnprintf(NULL, 0, format, ap);
    char* str = allocate(str, sizeof(char) * length + 1);

    vsnprintf(str, length + 1, format, ap);

    *buffer = str;


    return length;
}

int asprintf(char** buffer, const char* format, ...)
{
    char** buff;
    va_list ap;
    va_start(ap, format);

    int length = vasprintf(&buffer, format, ap);

    va_end(ap);

    return length;
}

void _gsprintf(void *addr)
{
    General* object = addr;

    char *buffer;

    asprintf(buffer, "%$", object->value);


}
/* 
void gprint(void *o, ...)
{
    va_list arg_list;
    General arg;

    va_start(arg_list, o);

    typeof( ((General* )o)->value) k;
}
 */