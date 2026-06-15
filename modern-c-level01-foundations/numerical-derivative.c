#include <stdio.h>
#include <math.h>
#include <complex.h>

double f (double x) {
    return x * x;
}

double complex f_complex(double complex x) {
    return x * x;
}

double f_sin (double x) {
    return sin(x);
}

double f_cos (double x) {
    return cos(x);
}

double f_sqrt (double x) {
    return sqrt(x);
}

double derivative (double x) {
    double h = 0.0001;
    return (f(x + h) - f(x)) / h;
}

double derivative_sin (double x) {
    double h = 0.0001;
    return (f_sin(x + h) - f_sin(x)) / h;
}

double derivative_cos (double x) {
    double h = 0.0001;
    return (f_cos(x + h) - f_cos(x)) / h;
}

double derivative_sqrt (double x) {
    double h = 0.0001;
    return (f_sqrt(x + h) - f_sqrt(x)) / h;
}

double complex complex_derivative(double complex x) {
    double h = 0.0001;
    return (f_complex(x + h) - f_complex(x)) / h;
}

int main (void) {
    printf("Derivative value is %f\n", derivative(2));
    printf("Derivative sin value is %f\n", derivative_sin(2));
    printf("Derivative cos value is %f\n", derivative_cos(2));
    printf("Derivative sqrt value is %f\n", derivative_sqrt(2));
    printf("%g + %gi\n", creal(complex_derivative(2+3i)), cimag(complex_derivative(2+3i)));


    return 0;
}