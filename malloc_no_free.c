#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("malloc'ing 450 bytes\n");
    int *x = malloc(450);
    printf("malloc'ed address: %p\n", x);

    printf("exiting\n");
    return 0;
}