#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    char phone[20];
    struct Node* next;
} Node;

Node* addContact(Node* head, char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

void searchContact(Node* head, char* name) {
    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }

    printf("'%s' 연락처를 찾을 수 없음.\n", name);
}

Node* deleteContact(Node* head, char* name) {
    if (head == NULL) {
        printf("전화번호부 비어 있음.\n");
        return NULL;
    }

    if (strcmp(head->name, name) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("'%s' 연락처 삭제.\n", name);
        return head;
    }

    Node* current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->name, name) == 0) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("'%s' 연락처 삭제.\n", name);
            return head;
        }
        current = current->next;
    }

    printf("'%s' 연락처를 찾을 수 없음.\n", name);
    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("전화번호부가 비어 있음.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
        current = current->next;
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice;
    char name[50];
    char phone[20];

    while (1) {
        printf("\n <전화번호부> \n");
        printf("1. 전화번호 추가\n");
        printf("2. 전화번호 검색\n");
        printf("3. 전화번호 삭제\n");
        printf("4. 전체 출력\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("이름: ");
            scanf("%s", name);
            printf("전화번호: ");
            scanf("%s", phone);
            head = addContact(head, name, phone);
        } else if (choice == 2) {
            printf("검색 : ");
            scanf("%s", name);
            searchContact(head, name);
        } else if (choice == 3) {
            printf("삭제 : ");
            scanf("%s", name);
            head = deleteContact(head, name);
        } else if (choice == 4) {
            printList(head);
        } else if (choice == 5) {
            freeList(head);
            printf("종료.\n");
            break;
        } else {
            printf("다시 입력하세요.\n");
        }
    }

    return 0;
}
