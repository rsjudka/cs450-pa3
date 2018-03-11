#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("malloc'ing data array with 100 ints\n");
    int *data = malloc(sizeof(int) * 100);
    
    data[18] = 450;
    printf("data[18]: %d\n", data[18]);
    
    printf("freeing data\n");
    free(data);

    printf("data[18]: %d\n", data[18]);

    printf("exiting\n");
    return 0;
}