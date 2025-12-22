#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

void list_destroy(Node **head) {
    if (!head || !*head) {
        return;
    }

    list_destroy(&((*head)->next));
    free(*head);
    *head = NULL;
}


void list_print(const Node *head){
    if(!head){
        printf("the list is empty\n");
        return;
    }
    const Node* temp=head;
    while(temp){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

Node *create_node(int value){
    Node *node=malloc(sizeof(Node));
    if(!node){
        return NULL;
    }
    node->data=value;
    node->next=NULL;
    return node;
}
int list_insert_end(Node **head,int value){
    Node *node=create_node(value);
    if(!node){
        list_destroy(head);
        return 0;
    }else{
        if(!*head){
            *head=node;
        }else{
            Node *temp=*head;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=node;
        }
    }
    return 1;
}
int list_insert_front(Node **head, int value){
    Node *node=create_node(value);
    if(!node){
        list_destroy(head);
        return 0;
    }else{
        if(!*head){
            *head=node;
        }else{
            Node *temp=*head;
            *head=node;
            (*head)->next=temp;
        }
        return 1;
    }

}
Node *find_Node(Node **head,int value){
    Node *temp=*head;
    while(temp && temp->data!=value){
        temp=temp->next;
    }
    return temp;
}
int list_delete_value(Node **head,int value){
    if(!*head){
        printf("the list is empty\n");
        return 1;
    }
    Node *node=find_Node(head,value);
    if(!node){
        return 1;
    }else{
        Node *temp=*head;
        while(temp->next && temp->next!=node){
            temp=temp->next;
        }
        if(temp->next){
            temp->next=node->next;
        }
    }
    return 1;
}
int main(){
    Node *head;
    head=NULL;
    list_insert_front(&head,1);
    list_insert_front(&head,2);
    list_insert_front(&head,3);
    list_insert_end(&head,4);
    list_delete_value(&head,2);
    list_print(head);
    return 0;
}