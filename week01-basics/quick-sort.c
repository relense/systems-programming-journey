#include <stdio.h>

// void quickSort (double unordered_array[], size_t pivot_index, size_t array_size) {
    
    
// }

void partition(double unordered_array[], size_t start, size_t end, size_t pivot_index) {
    size_t small_ends = start;
    size_t big_ends = end;
    size_t array_size = end - start + 1;
    double partitioned_array[array_size];

    for(size_t i = start; i <= end; ++i) {
        if(i == pivot_index) continue;

        if(unordered_array[i] < unordered_array[pivot_index]) {
            partitioned_array[small_ends - start] = unordered_array[i];
            ++small_ends;
        } else {
            partitioned_array[big_ends - start] = unordered_array[i];
            --big_ends;
        }    
    }

    for(size_t i = start; i <= end; ++i) {
        if (i >= (size_t) small_ends && i <= (size_t) big_ends) {
            unordered_array[i] = unordered_array[pivot_index];
        } else {
            unordered_array[i] = partitioned_array[i - start];
        }
    }
}



int test(double const array[], size_t array_size) {
    for(size_t i = 1; i < array_size - 1; ++i) {
        if(array[i] < array[i - 1]) {
            return 0;
        }
    } 

    return 1;
}

int main (void) {
//   double unordered_array[5] = {
//         [0] = 5.0,
//         [1] = 3.2,
//         [2] = 30.3,
//         [3] = 27.0,
//         [4] = 4.0,
//     };


    // quickSort(unordered_array, 3, 5);

    return 0;
}