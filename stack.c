#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int *arr;
    int top;
    int capacity;
}stack;

void resize(stack *st){
    (st)->capacity+=5;
    int *temp=(int*)realloc((st)->arr,(st)->capacity*sizeof(int));
    if(!temp){
        printf("resize failed!\n");
        exit(0);
    }
    st->arr=temp;
}

void push(stack *st,int data){
    if(st->top==st->capacity-1){
        resize(st);
    }
    st->arr[++st->top]=data;
    printf("%d is pushed\n",data);
}

void pop(stack *st){
    if(st->top==-1){
        printf("stack is empty\n");
    }else{
        printf("%d is popped\n",st->arr[st->top--]);
    }
}

void initialize(stack **st){
    *st=(stack*)malloc(sizeof(stack));
    if(!*st){
        printf("memory allocation failed\n");
        exit(0);
    }
    (*st)->top=-1;
    (*st)->capacity=5;
    (*st)->arr=(int*)malloc(5*sizeof(int));
    if(!(*st)->arr){
        printf("memory allocation failed\n");
        exit(0);
    }
}

int main() {
    stack *st;
    int choice, value;

    initialize(&st);

    while (1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(st, value);
                break;

            case 2:
                pop(st);
                break;

            case 3:
                printf("Exiting...\n");
                free(st->arr);
                free(st);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}