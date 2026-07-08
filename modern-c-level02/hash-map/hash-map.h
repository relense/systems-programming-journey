#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct entry entry;

 struct entry {
    char* key;
    double value;
    entry* next;
};

typedef struct {
    size_t len;
    size_t cap;
    entry** buckets;
} hash_map;

//part 1 -- exist in stack
hash_map* hash_map_init(hash_map* map, size_t cap);
void hash_map_destroy(hash_map* map);

//part 2 -- struct in heap
hash_map* hash_map_new(size_t cap);
void hash_map_delete(hash_map* map);

//operations
hash_map* hash_map_put(hash_map* map, char* key, double value);
bool hash_map_remove(hash_map* map, char* key, double* out_value);
double* hash_map_get(hash_map* map, char* key);
size_t hash_map_get_length(hash_map* map);
size_t hash_map_get_cap(hash_map* map);

#endif