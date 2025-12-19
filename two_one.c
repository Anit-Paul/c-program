#include<stdio.h>
#include<stdlib.h>
int main(){
    int *arr;
    int rows,cols,data;
    scanf("%d %d",&rows,&cols);
    arr=(int*)malloc(rows*cols*sizeof(int));
    if(!arr){
        printf("memory allocation fails\n");
        exit(0);
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",& data);
            arr[i*rows+j]=data;
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d\t",arr[i*rows+j]);
        }
        printf("\n");
    }
    free(arr);
}