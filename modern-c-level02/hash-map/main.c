#include "hash-map.h"

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("Part 1 store in stack\n");

    hash_map map;
  
    hash_map_init(&map, 4);
    printf("The hash_map has a cap of %zu\n", hash_map_get_cap(&map));
    hash_map_put(&map, "key1", 10.0);
    printf("The hash_map has a lenght of %zu\n", hash_map_get_length(&map));
    hash_map_put(&map, "key2", 2.0);
    printf("The hash_map has a lenght of %zu\n", hash_map_get_length(&map));
    hash_map_put(&map, "key3", 64.0);
    printf("The hash_map has a lenght of %zu\n", hash_map_get_length(&map));
    printf("The hash_map has a cap of %zu\n", hash_map_get_cap(&map));
    printf("The value with key3 is %f\n", *hash_map_get(&map, "key3"));

    hash_map_destroy(&map);
    printf("The hash_map is now %s\n", !map.buckets ? "NULL" : "not NULL");


    printf("\nPart 2 store in the heap\n");

    hash_map* heap_map = hash_map_new(4);

    printf("The hash_map has a cap of %zu\n", hash_map_get_cap(heap_map));
    hash_map_put(heap_map, "key1", 10.0);
    printf("The hash_map has a lenght of %zu\n", hash_map_get_length(heap_map));
    hash_map_put(heap_map, "key2", 2.0);
    printf("The hash_map has a lenght of %zu\n", hash_map_get_length(heap_map));
    hash_map_put(heap_map, "key3", 64.0);
    hash_map_put(heap_map, "key4", 14.0);
    hash_map_put(heap_map, "key6", 13.0);
    printf("The hash_map has a lenght of %zu\n", hash_map_get_length(heap_map));
    printf("The hash_map has a cap of %zu\n", hash_map_get_cap(heap_map));
    printf("The value with key3 is %f\n", *hash_map_get(heap_map, "key3"));

    hash_map_delete(heap_map);


    return EXIT_SUCCESS;
}