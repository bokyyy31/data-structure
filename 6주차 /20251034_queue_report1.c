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
}

bool isEmpty(LinearQueue *q) {
    return q->rear < q->front;
}

bool isFull(LinearQueue *q) {
    return q->rear == SIZE - 1;
}

bool enqueue(LinearQueue *q, int value) {
    if (isFull(q)) {
        printf("큐가 다 찼음.\n");
        return false;
    }
    q->rear++;
    q->data[q->rear] = value;
    return true;
}

int dequeue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있음. 초기화.\n");
        initQueue(q); 
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

void printQueue(LinearQueue *q) {
    if (isEmpty(q)) {
        printf("큐가 비어 있음.\n");
        return;
    }
    printf("큐 : ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\n[메뉴]\n");
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 큐 출력\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("삽입값: ");
            scanf("%d", &value);
            enqueue(&q, value);
        } else if (choice == 2) {
            int result = dequeue(&q);
            if (result != -1) {
                printf("삭제값: %d\n", result);
            }
        } else if (choice == 3) {
            printQueue(&q);
        } else if (choice == 4) {
            printf("프로그램 종료.\n");
            break;
        } else {
            printf("잘못된 입력.\n");
        }
    }

    return 0;
}
