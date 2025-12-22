#include<stdio.h>
void add(int *restrict a,int *restrict b){
    *a+=10;
    *b+=10;
}
int main(){
    int a=10,b=20;
    add(&a,&b);
    printf("%d %d",a,b);
}

/*restrict — Intermediate Explanation

The restrict keyword is used with pointers to inform the compiler that, for the lifetime of that pointer, no other pointer will access the same memory location.
This removes aliasing concerns, allowing the compiler to assume independence between memory accesses.

Because aliasing is eliminated, the compiler can safely apply optimizations such as keeping values in registers, reordering loads and stores, and vectorizing loops, which reduces expensive memory operations and improves performance.

Using restrict does not change program semantics when the promise is respected.
However, if restricted pointers alias (overlap), the program exhibits undefined behavior, since the compiler is free to optimize under the assumption that aliasing never occurs.*/