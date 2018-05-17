//
// Created by mahamdi on 5/16/18.
//
#include <stdio.h>
#include "function_seq.h"

int isPrime_seq(int number) {
    int i;
    if (number == 2) return 1;
    if (number % 2 == 0) return 0;
    for (i = 3; i * i <= number; i += 2)
        if (number % i == 0) return 0;
    return 1;
}

void find_N_Prime_Numbers_seq(int n, int *primeNumbers) {
    int count = 0;
    for (int i = 2; count < n; i++) {
        if (isPrime_seq(i)) {
            primeNumbers[count] = i;
            count++;
        }
    }
}

void print_Prime_Numbers(int primeNumbers[], int size) {
    for (int counter = 0; counter < size; counter++) {
        if (counter % 6 == 0)printf("\n");
        printf(" %5d ", primeNumbers[counter]);
    }
}
