#include <stdio.h>

void quickSort (double unordered_array[], size_t pivot_index, size_t array_size) {
    
    
}

void partition(double unordered_array[], size_t start, size_t end, size_t pivot_index) {
    size_t small_ends = start;
    size_t big_ends = end;
    size_t array_size = end - start + 1;
    double pivot_value = unordered_array[pivot_index];

    size_t i = start;
    while (i <= big_ends) {
        if(unordered_array[i] < pivot_value) {
            double temp = unordered_array[i];
            unordered_array[i] = unordered_array[small_ends];
            unordered_array[small_ends] = temp;
            ++small_ends;
            ++i;
        } else {
            double temp = unordered_array[i];
             unordered_array[i] = unordered_array[big_ends];
             unordered_array[big_ends] = temp;
            --big_ends;
        }    
    }

    for(size_t i = small_ends; i <= big_ends; ++i) {
        unordered_array[i] = pivot_value;
    }
}



int test(double const array[], size_t array_size) {
    for(size_t i = 1; i < array_size; ++i) {
        if(array[i] < array[i - 1]) {
            return 0;
        }
    } 

    return 1;
}

int main (void) {
  double unordered_array[5] = {
        [0] = 5.0,
        [1] = 3.2,
        [2] = 30.3,
        [3] = 27.0,
        [4] = 4.0,
    };


    quickSort(unordered_array, 3, 5);

    return 0;
}