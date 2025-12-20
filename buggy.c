#include <stdio.h>
#include <stdlib.h>

void append(int **arr, int *size, int value) {
    (*size)++;
    int *temp=realloc(*arr, (*size) * sizeof(int));
    if(!temp){
        printf("memory allocation fails\n");
        (*size)--;
        exit(0);
    }
    *arr =temp;
    (*arr)[*size - 1] = value;
}

int main() {
    int size = 0;
    int *arr = NULL;

    append(&arr, &size, 10);
    append(&arr, &size, 20);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
