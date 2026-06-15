#include <stdio.h>

int newHour(int current_hour, int hours) {
    return (current_hour + hours) % 24;
}

int main(void) {
    printf("Your new hour from 10h is %d\n", newHour(10, 3));
    printf("Your new hour from 20h is %d\n", newHour(20, 8));

    return 0;
}