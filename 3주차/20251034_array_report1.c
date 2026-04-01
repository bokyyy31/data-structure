#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option); 

int main() {
    int scores[30];
    int studentNumber;
    double average;

    srand(time(0));

    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101;
    }

    average = calculateAverage(scores, 30);
    printf("평균 : %.2f\n", average);

    printf("번호 입력(1번 ~ 30번): ");
    scanf("%d", &studentNumber);
    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d번 점수: %d\n", studentNumber, score);
    } else {
        printf("없는 번호입니다.\n");
    }

    printf("\n[모든 학생]\n");
    printScore(scores, 30, average, 0);

    printf("\n[평균 이상]\n");
    printScore(scores, 30, average, 1);

    printf("\n[평균 미만]\n");
    printScore(scores, 30, average, 2);

    return 0;
}

double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    } else {
        return -1;
    }
}

void printScore(int scores[], int size, double average, int option) {
    for (int i = 0; i < size; i++) {
        if (option == 0) {                       
            printf("%d번 점수: %d점\n", i + 1, scores[i]);
        } else if (option == 1) {                
            if (scores[i] >= average) {
                printf("%d번 점수: %d점\n", i + 1, scores[i]);
            }
        } else if (option == 2) {                
            if (scores[i] < average) {
                printf("%d번 점수: %d점\n", i + 1, scores[i]);
            }
        }
    }
}
