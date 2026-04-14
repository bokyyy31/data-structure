#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct {
    char documentName[50];
    int numPages;
} PrintJob;

typedef struct {
    PrintJob queue[SIZE];
    int front;
    int rear;
} PrintQueue;

void initQueue(PrintQueue *q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(PrintQueue *q) {
    return q->front == q->rear;
}

bool isFull(PrintQueue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

bool enqueue(PrintQueue *q, char *documentName, int numPages) {
    if (numPages > 50) {
        printf("페이지 수 50장을 초과.\n");
        return false;
    }
    if (isFull(q)) {
        printf("대기열이 참.\n");
        return false;
    }
    strcpy(q->queue[q->rear].documentName, documentName);
    q->queue[q->rear].numPages = numPages;
    q->rear = (q->rear + 1) % SIZE;
    printf("작업 '%s' (%d 페이지)을 대기열에 추가.\n", documentName, numPages);
    return true;
}

PrintJob dequeue(PrintQueue *q) {
    if (isEmpty(q)) {
        printf("비어 있음.\n");
        PrintJob emptyJob = {"", 0};
        return emptyJob;
    }
    PrintJob job = q->queue[q->front];
    q->front = (q->front + 1) % SIZE;
    return job;
}

void cancelJob(PrintQueue *q, char *documentName) {
    if (isEmpty(q)) {
        printf("비어있음.\n");
        return;
    }

    int found = 0;
    int i = q->front;
    while (i != q->rear) {
        if (strcmp(q->queue[i].documentName, documentName) == 0) {
            found = 1;
            int j = i;
            while (j != q->rear - 1) {
                q->queue[j] = q->queue[(j + 1) % SIZE];
                j = (j + 1) % SIZE;
            }
            q->rear = (q->rear - 1 + SIZE) % SIZE;
            printf("'%s' 작업취소.\n", documentName);
            return;
        }
        i = (i + 1) % SIZE;
    }

    if (!found) {
        printf("문서없음음.\n");
    }
}

void clearQueue(PrintQueue *q) {
    initQueue(q);
    printf("초기화\n");
}

void printQueue(PrintQueue *q) {
    if (isEmpty(q)) {
        printf("비어있음.\n");
        return;
    }
    printf("대기 중 : \n");
    int i = q->front;
    while (i != q->rear) {
        printf("- %s (%d 페이지)\n", q->queue[i].documentName, q->queue[i].numPages);
        i = (i + 1) % SIZE;
    }
}

int main() {
    PrintQueue q;
    initQueue(&q);

    int choice;
    char documentName[50];
    int numPages;

    while (true) {
        printf("\n1. 작업추가\n2. 작업처리\n3. 인쇄취소\n4. 대기열 비우기\n5. 대기열출력\n6. 종료\n선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("문서 : ");
            scanf("%s", documentName);
            printf("페이지수: ");
            scanf("%d", &numPages);
            enqueue(&q, documentName, numPages);
        } else if (choice == 2) {
            PrintJob job = dequeue(&q);
            if (strlen(job.documentName) > 0) {
                printf("작업 '%s' (%d 페이지)처리중.\n", job.documentName, job.numPages);
            }
        } else if (choice == 3) {
            printf("취소문서 : ");
            scanf("%s", documentName);
            cancelJob(&q, documentName);
        } else if (choice == 4) {
            clearQueue(&q);
        } else if (choice == 5) {
            printQueue(&q);
        } else if (choice == 6) {
            printf("종료.\n");
            return 0;
        } else {
            printf("다시 입력하세요.\n");
        }
    }
}
