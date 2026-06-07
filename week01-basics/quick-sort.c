#include <stdio.h>

void quickSort (double unordered_array[], size_t start, size_t end) {

    if(start >= end) {
        return;
    }

    size_t small_ends = start;
    size_t big_ends = end;
    double pivot_value = unordered_array[start + (end - start) / 2];

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
             if(big_ends > 0) {
                 --big_ends;
             } else {
                ++i;
             }
        }       
    }

    if(big_ends >= small_ends  && big_ends <= end) {
        for(size_t i = small_ends; i <= big_ends; ++i) {
            unordered_array[i] = pivot_value;
        }
    }


    if(small_ends > start) {
        quickSort(unordered_array, start, small_ends - 1);
    }

    if(big_ends > start && big_ends < end) { 
        quickSort(unordered_array, big_ends + 1, end);
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


    quickSort(unordered_array, 0, 4);

    int testResult = test(unordered_array, 5);

    for(size_t i = 0; i < 5; ++i) {
        printf("%.1f ", unordered_array[i]);
    }

    if(testResult == 1) {
        printf("True\n");
        return 0;
    } else {
        printf("False\n");
        return 1;
    }

}