#include <stdio.h>

void pointers_swap(double* p0, double* p1, double* p2) {
        double temp = *p0;
        *p0 = *p2; 
        *p2 = *p1; 
        *p1 = temp;
}

double sum1(size_t len, double const* a) {
    double ret = 0.0;
    for(double const* p = a; p < a + len; ++p) {
        ret += *p;
    }

    return ret;
}

int main(void) {
    double value_1 = 1.0;
    double value_2 = 2.0;
    double value_3 = 3.0;

    pointers_swap(&value_1, &value_2, &value_3);

    printf("value_1 = %g, value_2 = %g, value_3 = %g\n", value_1, value_2, value_3);
}