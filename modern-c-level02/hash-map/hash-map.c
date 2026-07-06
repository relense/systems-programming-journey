#include "hash-map.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static void entry_destroy(entry* head) {
    if(head) {
        entry* current = head;

        while(current != NULL) {
            entry* next = current->next;
            free(current->key);
            free(current);
            current = next;
            
        };
    }
}

//This hash function is using the DJB2 is the algorithm used to convert a string to an integer in this case a size_t so its always a positive number.
static size_t hash(char* string) {
    size_t result = 5381; //the number used in the oficial djb2 
    size_t string_length = strlen(string);

    for(size_t i = 0; i < string_length; i++) {
        result = (result * 33) + string[i];
    }

    return result;
}

static hash_map* hash_map_insert(hash_map* map, entry* new_entry) {
    if(map && new_entry) {
        new_entry->next = NULL;
        size_t bucket_index = hash(new_entry->key) % map->cap;
        entry* current_bucket = map->buckets[bucket_index];
    
        if(!current_bucket) {
            map->buckets[bucket_index] = new_entry;
        } else {
            while(current_bucket->next != NULL) {
                current_bucket = current_bucket->next;
            }
    
            current_bucket->next = new_entry;
        }
    
        return map;
    }

    return NULL;
}

static hash_map* hash_map_resize(hash_map* map) {
    if(map) {
        //create space for the entries to be temporarily
        entry** temp_entries = malloc(sizeof(entry*[map->len]));
        //If allocation fails
        if(!temp_entries) return NULL;

        //to help keep track of the array position that comes next
        size_t visited_entries = 0;
        for(size_t i = 0; i < map->cap; i++){
            entry* head = map->buckets[i];
            while(head != NULL) {
                temp_entries[visited_entries] = head;
                visited_entries++;
                head = head->next;
            }
        }

        size_t new_cap = map->cap * 2;
        entry** new_buckets = realloc(map->buckets, sizeof(entry*[new_cap]));

        if(!new_buckets) return NULL;

        map->buckets = new_buckets;
        map->cap = new_cap;

        //clear all hash_map entries to prepare for new cap increase and realocation;
        for(size_t i = 0; i < map->cap; i++) {
            map->buckets[i] = NULL;
        }

        for(size_t j = 0; j < map->len; j++) {
            hash_map_insert(map, temp_entries[j]);
        }
    
        free(temp_entries);

        return map;

    }

    return NULL;
}

static entry* get_entry(hash_map* map, char* key) {
    if(map) {
        size_t bucket_index = hash(key) % map->cap;
        entry* current_entry = map->buckets[bucket_index];
    
        while(current_entry != NULL) {
            if(!strcmp(current_entry->key, key)) break;
            current_entry = current_entry->next;
        }
    
        if(current_entry == NULL) return NULL;
    
        return current_entry;
    }

    return NULL;
}

hash_map* hash_map_init(hash_map* map, size_t cap) {
    if(map) {
        if(cap) {
            *map = (hash_map) { 
                .cap = cap,
                .buckets = malloc(sizeof(entry*[cap]))
            };

            //If allocation fails
            if(!map->buckets) {
                map->cap = 0;
                printf("ESTOU AQUI");
                return NULL;
            }

            for(size_t i = 0; i < cap; i++) {
                map->buckets[i] = NULL;
            }

        } else {
            *map = (hash_map) { };
        }
    }

  return map;
}

void hash_map_destroy(hash_map* map) {
    if(map) {
        for(size_t i = 0; i < map->cap; i++) {
            entry_destroy(map->buckets[i]);
        }

        free(map->buckets);
        *map = (hash_map) {};
    }
}

hash_map* hash_map_new(size_t cap) {
    hash_map* map = malloc(sizeof(hash_map));

    if(!map) return NULL;

    if(!hash_map_init(map, cap)) {
        free(map);
        return NULL;
    }

    return map;
}

void hash_map_delete(hash_map* map) {
    if(map) {
        hash_map_destroy(map);
        free(map);
    }
}

hash_map* hash_map_put(hash_map* map, char* key, double value) {
    if (map) {
          entry* searched_entry = get_entry(map, key);

        if(searched_entry) {
            searched_entry->value = value;
            return map;
        }

        double load_factor = (double) map->len / map->cap;
        if(load_factor > 0.75) {
            if(!hash_map_resize(map)) return NULL;
        }

        entry* new_entry = malloc(sizeof(entry));
        if(!new_entry) return NULL;

        *new_entry = (entry) {
            .key = strdup(key),
            .value = value,
            .next = NULL
        };

        if(!hash_map_insert(map, new_entry)) return NULL;
        map->len++;
        return map;
    }

    return NULL;
}

bool hash_map_remove(hash_map* map, char* key, double* out_value) {
    if(map) {
        if(!get_entry(map, key)) return false;

        size_t bucket_index = hash(key) % map->cap;
        entry* to_remove = map->buckets[bucket_index];

        //if the first element of the linked list is the one we want
        if(!strcmp(to_remove->key, key)) {
            *out_value = to_remove->value;
            map->buckets[bucket_index] = to_remove->next;

            free(to_remove->key);
            free(to_remove);
        } else {
            entry* prev = NULL;

            while(to_remove != NULL) {
                if(!strcmp(to_remove->key, key)) break;
                prev = to_remove;
                to_remove = to_remove->next;
            }

            *out_value = to_remove->value;
            prev->next = to_remove->next;
            free(to_remove->key);
            free(to_remove);
        }

        map->len--;

        return true;
    }

    return false;
}

double* hash_map_get(hash_map* map, char* key) {
    if(map) {
        entry* entry_elem = get_entry(map, key);
        if(!entry_elem) return NULL;
        return &entry_elem->value;
    }

    return NULL;
}

size_t hash_map_get_length(hash_map* map) {
     if(map) return map->len;
     return 0;
}

size_t hash_map_get_cap(hash_map* map) {
    if(map) return map->cap;
    return 0;
}