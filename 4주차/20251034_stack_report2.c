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
    int valid = 1; 

    for (int i = 0; i < len; i++) {
        char c = str[i];

        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        }
        
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s)) {
                valid = 0; 
                break;
            }
            char top = pop(&s);

            if (c == ')' && top != '(') { valid = 0; break; }
            if (c == '}' && top != '{') { valid = 0; break; }
            if (c == ']' && top != '[') { valid = 0; break; }
        }
    }

    if (!isEmpty(&s)) {
        valid = 0;
    }

    if (valid == 1) {
        printf("유효한 괄호\n");
    } else {
        printf("유효하지 않은 괄호\n");
    }

    freeStack(&s);
    return 0;
}
