#include <stdio.h>
#include <stdlib.h>

int vector_to_vector (int array_A[], int array_B[], size_t array_size) {
    int result = 0;

    for(size_t i = 0; i < array_size; ++i) {
        result += array_A[i] * array_B[i];
    }

    return result;
}

void matrix_to_vector(int array_A[], int matrix[][3], size_t array_size) {
    int result_0 = vector_to_vector(matrix[0], array_A, array_size);
    int result_1 = vector_to_vector(matrix[1], array_A, array_size);
    int result_2 = vector_to_vector(matrix[2], array_A, array_size);

    int result_array[] = { result_0, result_1, result_2 };

    for(size_t i = 0; i < array_size; ++i) {
        printf("Result[%zu] = %d\n", i, result_array[i]);
    }
}

int main(void) {

    int array_A[5] = {
        [0] = 9,
        [1] = 2,
        [2] = 15,
    };
    
    int array_B[5] = {
        [0] = 9,
        [1] = 2,
        [2] = 15,
    };

    int matrix[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };

    printf("The vector to vector result is %d\n", vector_to_vector(array_A, array_B, 3));

    matrix_to_vector(array_A, matrix, 3);
    

    return EXIT_SUCCESS;
}