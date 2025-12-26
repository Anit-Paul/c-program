#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fptr;
    //Read a file
    /*fptr=fopen("extra.txt","r");
    char *data=(char*)malloc(50*sizeof(char));
    while(fgets(data,50,fptr)){
        printf("%s",data);
    }
    free(data);*/
    //write in the file
    /*fptr=fopen("temp.txt","a");
    printf("enter your data : ");
    char *data=(char*)malloc(50*sizeof(char));
    fgets(data,50,stdin);
    printf("%s",data);
    fputs(data,fptr);
    fclose(fptr);*/
    //removing a file
    if(remove("temp.txt")){
        printf("file removed successfully\n");
    }else{
        printf("file can not be removed");
    }
    
}