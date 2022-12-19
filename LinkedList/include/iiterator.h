#ifndef _IITERATOR_H_
#define _IITERATOR_H_

typedef struct _IIterator IIterator;

struct _IIterator
{
	int (*hasNext)(IIterator*);
	int (*next)(IIterator*);
};

#endif // !_IITERATOR_H_