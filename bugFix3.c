#include <stdio.h>
#include <stdlib.h>

int* createArray() {
    int arr[3] = {10, 20, 30};
    return arr;
}

void modify(int *p) {
    p[0] = 100;
}

int main() {
    int *ptr = createArray();
    modify(ptr);

    printf("%d\n", ptr[0]);
    free(ptr);

    return 0;
}
