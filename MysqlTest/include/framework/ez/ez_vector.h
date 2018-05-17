

#ifndef _EZ_VECTOR_H
#define _EZ_VECTOR_H

#include <data_types.h>

struct ezVector
{
	t_uint32 size;

	t_uint32 usedMax;
	
	void **index;
};


struct ezVector *ezVectorNew(t_uint32 size);
void ezVectorFree(struct ezVector *vec);

t_uint32 ezVectorMax(struct ezVector *vec);

void *ezVectorIndex(struct ezVector *vec, t_uint32 index);
void *ezVectorLoopupIndex(struct ezVector *vec, t_uint32 index);
t_uint32 ezVectorSet(struct ezVector *vec, void *val);

t_uint32 ezVectorSetIndex(struct ezVector *vec, t_uint32 index, void *val);
void ezVectorReset(struct ezVector *vec);

#endif


