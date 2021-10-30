#pragma once
#include "TypeDef.h"
#include <stdint.h>

//##############################
//DEFINITIONS
//##############################
#define BUCKET_ARRAY_INIT_SIZE 1

//##############################
//STRUCTS
//##############################
typedef struct HashNode
{
	const char* key;
	voidPtr_t value;
	uint64_t hash_code;

	struct HashNode* next;
} HashNode;

typedef struct HashMap
{
	HashNode** bucket_array;
	uint32_t num_buckets;
	uint32_t size;
} HashMap;

//##############################
//FUNCTIONS
//##############################
void HashMapInitialize(HashMap* _hashMap);
voidPtr_t HashMapRemove(HashMap* _hashMap, const char* _key);
voidPtr_t HashMapGet(const HashMap* _hashMap, const char* _key);
void HashMapAdd(HashMap* _hashMap, const char* _key, voidPtr_t _value);
void HashMapDestroy(HashMap* _hashMap);

//##############################
//PRIVATE
//##############################
static uint64_t HashCode(const char* _key);
static uint32_t GetBucketIndex(const HashMap* _hashMap, const char* _key);
