#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Buffer;

void init(Buffer *buf) {
    buf->size = 0;
    buf->capacity = 2;
    buf->data = malloc(buf->capacity * sizeof(int));
}

void push(Buffer *buf, int value) {
    if (buf->size == buf->capacity) {
        buf->capacity *= 2;
        buf->data = realloc(buf->data, buf->capacity * sizeof(int));
    }
    buf->data[buf->size++] = value;
}

void destroy(Buffer *buf) {
    free(buf);
}

int main() {
    Buffer *buf = malloc(sizeof(Buffer));
    init(buf);

    push(buf, 10);
    push(buf, 20);
    push(buf, 30);

    for (int i = 0; i < buf->size; i++) {
        printf("%d ", buf->data[i]);
    }

    destroy(buf);
    return 0;
}
