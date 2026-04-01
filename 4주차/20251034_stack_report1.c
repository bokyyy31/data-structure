#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

void initStack(Stack *s, int initialSize) {
    s->data = (int *)malloc(initialSize * sizeof(int));
    s->top = -1;
    s->capacity = initialSize;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

void expandStack(Stack *s) {
    int newCapacity = s->capacity + 5;
    s->data = (int *)realloc(s->data, newCapacity * sizeof(int));
    s->capacity = newCapacity;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        expandStack(s);
    }
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->data[(s->top)--];
}

void freeStack(Stack *s) {
    free(s->data);
}

int main() {
    Stack s;
    initStack(&s, 100); 

    char str[101]; 

    printf("문자열을 입력하세요: ");
    scanf("%100[^\n]", str);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    printf("거꾸로 출력된 문자열: ");
    while (!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");

    freeStack(&s);
    return 0;
}
