#include <stdio.h>

void fun(int *p) {
    p++;
    *p = *p + 5;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int *p = arr;

    fun(p);
    printf("%d %d %d", arr[0], arr[1], arr[2]);

    return 0;
}
