#include <stdio.h>

int main(void) {
    const char* pi = "3.1415926535897932384626433832795028841971...";

    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("N must be a positive number\n");
        return 1;
    }

    for(int i = 0; i < n && pi[i] != '\0'; ++i) {
        printf("%c", pi[i]);
    }

    printf("\n");

    return 0;
}