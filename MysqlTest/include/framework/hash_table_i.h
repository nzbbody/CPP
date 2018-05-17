/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */
 

#ifndef _HASH_TABLE_I_H
#define _HASH_TABLE_I_H

#include <data_types.h>


struct hashTableIEntry;
struct hashTableIOps;
struct hashTableI;


typedef t_uint32 (*hashTableIHashKeyProc)(const void *key);
typedef t_bool (*hashTableIMatchEntryProc)(const void *key1, const void *key2);
typedef void (*hashTableIKeyDestroyProc)(const void *key);
typedef void (*hashTableIValueDestroyProc)(const void *value);





struct hashTableIEntry
{
	t_uint32 hashKeyNumber;
};



struct hashTableIOps
{

	hashTableIHashKeyProc hashKey;
	hashTableIMatchEntryProc matchEntry;
	hashTableIKeyDestroyProc keyDestroy;
	hashTableIValueDestroyProc valueDestroy;

};

struct hashNode
{
	hashNode() : key(0), value(0), next(0), hashKey(0) { }
	const void *key;
	const void *value;
	hashNode *next;
	t_uint32 hashKey;
};


struct hashTableIterator;

struct hashTableI
{

	hashTableI(hashTableIOps *ops = 0, t_int32 size = 11);
	virtual ~hashTableI();
	
	
	t_bool hashTableIOpsSet(hashTableIOps *ops);
	t_bool hashTableIAdd(const void *key, const void *value);
	t_bool hashTableILookup(const void *key, const void **value);
	t_bool hashTableDel(const void *key);

	hashTableIterator begin();
	hashTableIterator end();

private:
	t_bool hashTableIAddInternal(const void * key, const void *value, t_bool useNewKey);
	t_bool hashTableIDelInternal(const void *key);
	t_bool hashTableIDelNode(hashNode ***nodePtrPtr);
	hashNode **hashTableILookupInternal(const void *key, t_uint32 *hashKey);

public:
	hashTableIOps *mOps;

	t_int32 mSize;
	t_int32 mNodeCounts;
	hashNode **mNodes;
};




struct hashTableIterator 
{
public:
	hashTableIterator() {};
	
	hashTableIterator(hashNode **node, t_int32 curSize, hashTableI *hashTable) : 
		mCurNode(node), 
		mCurSize(curSize),
		mHashTable(hashTable)
		{};

	const void * operator*();
	hashTableIterator& operator++();
	t_bool operator!=(const hashTableIterator &_p) const;

	void incr();
	
	hashNode **mCurNode;
	t_int32 mCurSize;
	hashTableI *mHashTable;
	
};





#endif

