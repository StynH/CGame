#include "HashMap.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void HashMapInitialize(HashMap* _hashMap)
{
    _hashMap->num_buckets = BUCKET_ARRAY_INIT_SIZE;
    _hashMap->size = 0;

    _hashMap->bucket_array = malloc(BUCKET_ARRAY_INIT_SIZE * sizeof(HashNode));
    if(_hashMap->bucket_array)
    {
        for (uint32_t i = 0; i < BUCKET_ARRAY_INIT_SIZE; ++i)
        {
            _hashMap->bucket_array[i] = NULL;
        }
    }
}

void* HashMapRemove(HashMap* _hashMap, const char* _key)
{
	const uint32_t bucketIndex = GetBucketIndex(_hashMap, _key);
    const uint64_t hashCode = HashCode(_key);
    HashNode* head = _hashMap->bucket_array[bucketIndex];
    
    HashNode* prev = NULL;
    while (head) 
    {
        if (strcmp(head->key, _key) == 0 && hashCode == head->hash_code) 
        {
            break;
        }
        
        prev = head;
        head = head->next;
    }
    
    if (!head) 
    {
        return NULL;
    }
    
    _hashMap->size--;
    
    if (prev) 
    {
        free(prev->next);
        prev->next = head->next;
    }
    else 
    {
        _hashMap->bucket_array[bucketIndex] = head->next;
    }

    return head->value;
}

void* HashMapGet(const HashMap* _hashMap, const char* _key)
{
	const uint32_t bucketIndex = GetBucketIndex(_hashMap, _key);
    const uint64_t hashCode = HashCode(_key);
    HashNode* head = _hashMap->bucket_array[bucketIndex];
    
    while (head) 
    {
        if (strcmp(head->key, _key) == 0 && head->hash_code == hashCode) 
        {
            return head->value;
        }
        head = head->next;
    }
    
    return NULL;
}

void HashMapAdd(HashMap* _hashMap, const char* _key, void* _value)
{
	const uint32_t bucketIndex = GetBucketIndex(_hashMap, _key);
	const uint64_t hashCode = HashCode(_key);
    HashNode* head = _hashMap->bucket_array[bucketIndex];
    
    while (head) 
    {
        if (strcmp(head->key, _key) == 0 && head->hash_code == hashCode) 
        {
            head->value = _value;
            return;
        }
        head = head->next;
    }
    
    _hashMap->size++;
    head = _hashMap->bucket_array[bucketIndex];

    HashNode* newNode = malloc(sizeof(HashNode));
    if (newNode)
    {
        newNode->key = _key;
        newNode->value = _value;
        newNode->hash_code = hashCode;
        newNode->next = head;

        _hashMap->bucket_array[bucketIndex] = newNode;
    }

    if ((1.0 * _hashMap->size) / _hashMap->num_buckets >= 0.7) 
    {
        const uint32_t tempSize = _hashMap->num_buckets;
        HashNode** newArray = realloc(_hashMap->bucket_array, _hashMap->num_buckets * sizeof(HashNode));

        if(newArray)
        {
            _hashMap->num_buckets = _hashMap->num_buckets * 2;
            _hashMap->size = 0;
            _hashMap->bucket_array = newArray;

            for (uint32_t i = tempSize; i < _hashMap->num_buckets; i++) 
            {
                _hashMap->bucket_array[i] = NULL;
            }

            for (uint32_t i = 0; i < tempSize; ++i) 
            {
                HashNode* headNode = _hashMap->bucket_array[i];
                while (headNode != NULL) {
                    HashMapAdd(_hashMap, headNode->key, headNode->value);
                    headNode = headNode->next;
                }
            }
        }
    }
}

void HashMapDestroy(HashMap* _hashMap)
{
    for(uint32_t i = 0; i < _hashMap->num_buckets; ++i)
    {
        free(_hashMap->bucket_array[i]);
    }
    free(_hashMap->bucket_array);
    free(_hashMap);
}

uint64_t HashCode(const char* _key)
{
    uint64_t hash = 5381;
    uint32_t c;

    while ((c = (uint8_t)*_key++)) 
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

uint32_t GetBucketIndex(const HashMap* _hashMap, const char* _key)
{
	const uint64_t hashCode = HashCode(_key);
    int32_t index = (int32_t)(hashCode % _hashMap->num_buckets);
    index = index < 0 ? index * -1 : index;
    return index;
}
