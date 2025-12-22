#include<stdio.h>
/*int add(int a,int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}
void calculate(int a,int b,int (*op)(int,int)){
    printf("%d\n",op(a,b));
}
int main(){
    //int (*fptr)(int,int);
    //fptr=&add;
    //printf("%d",fptr(1,2));
    calculate(1,2,add); //function callback
    calculate(1,2,subtract); //function callback
    return 0;
}*/
//function pointer with structure
typedef struct shape{
    int h,w;
    void (*greet)();
    int (*area)(int,int);
    int (*perimeter)(int,int);
}shape;

void shape_greet(){
    printf("hello i am a rectriangle\n");
}

int shape_area(int a,int b){
    return a*b;
}

int shape_perimeter(int a,int b){
    return 2*(a+b);
}

void initialize(shape *sh){
    sh->h=10;
    sh->w=5;
    sh->greet=shape_greet;
    sh->area=shape_area;
    sh->perimeter=shape_perimeter;
}
int main(){
    shape sh;
    initialize(&sh);
    sh.greet();
    printf("%d\n",sh.area(sh.h,sh.w));
    printf("%d\n",sh.perimeter(sh.h,sh.w));
    return 0;
}