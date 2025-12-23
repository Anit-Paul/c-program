#include <stdio.h>
#include <stdlib.h>

/* ================== NODE DEFINITION ================== */

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

/* ================== COMPARATOR TYPE ================== */

typedef int (*cmp_fn)(const void *, const void *);

/* ================== NODE CREATION ================== */

Node *create_node(void *data) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        printf("Node allocation failed\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

/* ================== SORTED INSERT ================== */

int list_insert_sorted(Node **head, void *data, cmp_fn cmp) {
    Node *node = create_node(data);
    if (!node) return 0;

    /* Insert at head */
    if (!*head || cmp(data, (*head)->data) < 0) {
        node->next = *head;
        *head = node;
        return 1;
    }

    /* Insert in middle or end */
    Node *curr = *head;
    while (curr->next && cmp(data, curr->next->data) > 0) {
        curr = curr->next;
    }

    node->next = curr->next;
    curr->next = node;
    return 1;
}

/* ================== PRINT LIST (INT DATA) ================== */

void list_print_int(const Node *head) {
    while (head) {
        printf("%f ", *(float *)head->data);
        head = head->next;
    }
    printf("\n");
}

/* ================== DESTROY LIST ================== */

void list_destroy(Node **head, void (*free_data)(void *)) {
    while (*head) {
        Node *temp = *head;
        *head = (*head)->next;

        if (free_data)
            free_data(temp->data);

        free(temp);
    }
}

/* ================== INT COMPARATOR ================== */

int cmp_int(const void *a, const void *b) {
    return *(float *)a - *(float *)b;
}

/* ================== MAIN ================== */

int main() {
    Node *head = NULL;

    float *a = malloc(sizeof(float));
    float *b = malloc(sizeof(float));
    float *c = malloc(sizeof(float));
    float *d = malloc(sizeof(float));

    *a = 3.5;
    *b = 1.25;
    *c = 4.47;
    *d = 1.24;

    list_insert_sorted(&head, a, cmp_int);
    list_insert_sorted(&head, b, cmp_int);
    list_insert_sorted(&head, c, cmp_int);
    list_insert_sorted(&head, d, cmp_int);

    list_print_int(head);

    list_destroy(&head, free);

    return 0;
}
