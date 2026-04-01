#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addStudent(int **scores, int *size);
void deleteStudent(int *scores, int *size);
void searchStudent(int *scores, int size);
void printScore(int *scores, int size);

int main() {
    int size = 30; 
    int *scores = (int*)malloc(size * sizeof(int));

    srand(time(0));
    for (int i = 0; i < size; i++) {
        scores[i] = rand() % 101;
    }

    int choice;

    while (1) {
        printf("\n[학생정보 관리 프로그램]\n");
        printf("1. 학생 추가\n");
        printf("2. 학생 삭제\n");
        printf("3. 학생 검색\n");
        printf("4. 학생 출력\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addStudent(&scores, &size);
        } else if (choice == 2) {
            deleteStudent(scores, &size);
        } else if (choice == 3) {
            searchStudent(scores, size);
        } else if (choice == 4) {
            printScore(scores, size);
        } else if (choice == 5) {
            printf("종료.\n");
            break;
        } else {
            printf("재입력.\n");
        }
    }

    free(scores);
    return 0;
}

void addStudent(int **scores, int *size) {
    *size = *size + 1;
    *scores = (int*)realloc(*scores, *size * sizeof(int));
    (*scores)[*size - 1] = rand() % 101;
    printf("%d번 추가완료. 성적 : %d점\n", *size, (*scores)[*size - 1]);
}

void deleteStudent(int *scores, int *size) {
    int num;
    printf("삭제번호 입력 (1 ~ %d): ", *size);
    scanf("%d", &num);

    if (num < 1 || num > *size) {
        printf("번호 재입력.\n");
        return;
    }

    for (int i = num - 1; i < *size - 1; i++) {
        scores[i] = scores[i + 1];
    }
    *size = *size - 1;
    printf("%d번 삭제완료\n", num);
}

void searchStudent(int *scores, int size) {
    int num;
    printf("검색번호 입력 (1 ~ %d): ", size);
    scanf("%d", &num);

    if (num < 1 || num > size) {
        printf("번호 재입력.\n");
        return;
    }
    printf("%d번 : %d점\n", num, scores[num - 1]);
}

void printScore(int *scores, int size) {
    double sum = 0;
    printf("\n[전체 정보]\n");
    for (int i = 0; i < size; i++) {
        printf("%d번 : %d점\n", i + 1, scores[i]);
        sum += scores[i];
    }
    printf("평균 : %.2f\n", sum / size);
}
