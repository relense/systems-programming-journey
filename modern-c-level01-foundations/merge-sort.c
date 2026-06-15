#include <stdio.h>
#include <stdbool.h>

bool test (double const ordered_array[], size_t array_size) {
    for(int i = 1; i < array_size; ++i) {
        if(ordered_array[i - 1] > ordered_array[i]) {
            return false;
        }
    }

    return true;
}


void merge (double array[], int start, int middle, int end) {
    int array_size = (end - start) + 1;
    double temp_array[array_size];

    int temp_index = 0;
    int left_array_index = start;
    int right_array_index = middle + 1;

    for(int i = 0; i < array_size; i++) {
        if(left_array_index <= middle && (right_array_index > end || array[left_array_index] < array[right_array_index])) {
            temp_array[temp_index] = array[left_array_index];
            ++left_array_index;
        } else {
            temp_array[temp_index] = array[right_array_index];
            ++right_array_index;
        }

        ++temp_index;
    }

    for (int i = 0; i < array_size; i++) {
        array[start + i] = temp_array[i];
    }
}

void merge_sort (double unordered_array[], int start_index, int end_index) {
    if(start_index >= end_index) {
        return;
    }

    int middle = start_index + (end_index - start_index) / 2;

    merge_sort(unordered_array, start_index, middle);
    merge_sort(unordered_array, middle + 1, end_index);
    merge(unordered_array, start_index, middle, end_index);
}


int main(void) {
    double unordered_array[5] = {
        [0] = 5.0,
        [1] = 3.2,
        [2] = 30.3,
        [3] = 27.0,
        [4] = 4.0,
    };

    merge_sort(unordered_array, 0, 4);

   if (test(unordered_array, 5)) {
        printf("true\n");
        return 0;
    } else {
        printf("false\n");
        return 1;
    }
}
