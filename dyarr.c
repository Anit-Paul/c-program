#include<stdio.h>
#include<stdlib.h>
int **create_matrix(int rows,int cols){
    int **matrix;
    matrix=(int**)malloc(rows*sizeof(int*));
    if(!matrix){
        printf("memory is not allocated\n");
        exit(0);
    }
    for(int i=0;i<rows;i++){
        matrix[i]=(int*)malloc(cols*sizeof(int));
        if(!matrix[i]){
            printf("memory is not allocated!\n");
            exit(0);
        }
    }
    return matrix;
}
void set_value(int **matrix,int i,int j,int value){
    matrix[i][j]=value;
}
int get_value(int **matrix,int i,int j,int rows,int cols){
    if(0<=i<rows && 0<=j<cols){
        return matrix[i][j];
    }else{
        printf("user gave a wrong location\n");
        return -1;
    }
}
void free_matrix(int **matrix,int rows){
    for(int i=0;i<rows;i++){
        free(matrix[i]);
    }
    free(matrix);
}
int main(){
    int rows,cols;
    scanf("%d %d",&rows,&cols);
    int **matrix=create_matrix(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int value;
            scanf("%d",& value);
            set_value(matrix,i,j,value);
        }
    }
    int i,j;
    scanf("%d %d",&i,&j);
    printf("%d",get_value(matrix,i,j,rows,cols));
    free_matrix(matrix,rows);
    return 0;
}