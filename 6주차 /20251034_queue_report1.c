#include <stdio.h>
#include <stdbool.h>

#define SIZE 30 

typedef struct {
    int data[SIZE]; 
    int front;
    int rear;
} LinearQueue;

void initQueue(LinearQueue *q) {
    q->front = 0;
    q->rear = -1;

bool isEmpty(LinearQueue *q) {
    return q->rear < q->front; 
}

bool isFull(LinearQueue *q) {
    return q->rear == SIZE - 1; 
}

bool enqueue(LinearQueue *q, int value) {
    if (isFull(q)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;
    return true;
}

int dequeue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있습니다.\n");
        return -1;  // 큐가 비어 있을 때 -1 반환
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

int main() {
    LinearQueue q;
    initQueue(&q);
    int choice;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Dequeue: %d\n", dequeue(&q)); 
    printf("Dequeue: %d\n", dequeue(&q)); 

    enqueue(&q, 60); 
    enqueue(&q, 70); 

    while (!isEmpty(&q)) {
        printf("Dequeue: %d\n", dequeue(&q));  
    }

int value;

while (1) {
    printf("\n[메뉴]\n");
    printf("1. 삽입\n");
    printf("2. 삭제\n");
    printf("3. 큐 데이터 출력\n");
    printf("4. 종료\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("삽입할 값: ");
        scanf("%d", &value);
        enqueue(&q, value);

    } else if (choice == 2) {
        int result = dequeue(&q);
        if (result != -1) {
            printf("삭제된 값: %d\n", result);
        }

    } else if (choice == 3) {
        if (isEmpty(&q)) {
            printf("큐가 비어 있습니다.\n");
        } else {
            printf("큐 내용: ");
            for (int i = q.front; i <= q.rear; i++) {
                printf("%d ", q.data[i]);
            }
            printf("\n");

