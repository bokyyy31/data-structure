#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int scores[10];   
    int sum = 0;      
    double average;   

    srand(time(NULL));  

    
    for (int i = 0; i < 10; i++) {
        scores[i] = rand() % 101; 
        sum += scores[i];
        printf("학생 %d : %d\n", i + 1, scores[i]);
    }

    average = (double)sum / 10; 
    printf("\n평균 : %.2f\n", average);

    return 0;
}
