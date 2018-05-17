#include <stdio.h>
#include "function_seq.h"
#include "function_Parallele.c"

int verif(int tab1[], int tab2[], int size) {

    for (int counter = 0; counter < size; counter++) {
        if (tab1[counter] != tab2[counter]) {
            printf("%d", counter);
            return 0;
        }
    }
    return 1;
}


int main() {
    int n = 1000000;
    double start_time, end_time;
    //printf("How mush prime numbers would you like to find :\n");
    //scanf("%d", &n);
    int primeNumbers[n];
    int primeNumbers1[n];
    start_time = omp_get_wtime();
    find_N_Prime_Numbers_seq(n, primeNumbers);
    end_time = omp_get_wtime();
    //printf("the %d first prime numbers are :\n", n);
    //print_Prime_Numbers(primeNumbers, n);
    printf("\n\n sequential time=%f\n", end_time - start_time);
    start_time = omp_get_wtime();
    find_N_Prime_Numbers_parallele(n, primeNumbers1);
    end_time = omp_get_wtime();
    printf(" parallel time=%f\n", end_time - start_time);
    //printf("the %d first prime numbers are :\n", n);
    //print_Prime_Numbers(primeNumbers1, n);
    printf("verif :--------%d\n", verif(primeNumbers, primeNumbers1, n));
    return 0;
}


