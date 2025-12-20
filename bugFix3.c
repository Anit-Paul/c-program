#include <stdio.h>
#include <stdlib.h>

int* createArray() {
    int *arr=(int*)malloc(3*sizeof(int));
    if(!arr){
        printf("memory allocation fails for arr\n");
        exit(0);
    }
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    return arr;
}

void modify(int *p) {
    p[0] = 100;
}

int main() {
    int *ptr = createArray();
    if(!ptr){
        printf("memory allocation fails\n");
        exit(0);
    }
    modify(ptr);

    printf("%d\n", ptr[0]);
    free(ptr);
    return 0;
}
