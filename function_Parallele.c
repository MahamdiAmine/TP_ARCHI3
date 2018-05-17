//
// Created by mahamdi on 5/16/18.
//
#include <stdio.h>
#include <omp.h>
#include "function_seq.h"

int isPrime_parallele(int number) {
    int i;
    if (number == 2) return 1;
    if (number % 2 == 0) return 0;
    for (i = 3; i * i <= number; i += 2)
        if (number % i == 0) return 0;
    return 1;
}

void find_N_Prime_Numbers_parallele(int n, int *primeNumbers) {
    int count = 0, i;
#pragma omp parallel num_threads(4) private (i) shared(count)
    {
        for (i = 2; count < n; i++) {
            if (isPrime_seq(i)) {
                primeNumbers[count] = i;
                count++;

            }
        }
    }
}

