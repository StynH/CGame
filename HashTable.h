#pragma once
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
	void* value;
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
void* HashMapRemove(HashMap* _hashMap, const char* _key);
void* HashMapGet(HashMap* _hashMap, const char* _key);
void HashMapAdd(HashMap* _hashMap, const char* _key, void* _value);

//##############################
//PRIVATE
//##############################
static uint64_t HashCode(const char* _key);
static uint32_t GetBucketIndex(HashMap* _hashMap, const char* _key);
