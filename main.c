#include <stdio.h>
#include <stdbool.h>
#include <libnet.h>
#include <omp.h>

void SieveOfEratosthenes_sequential(int n)
{
    /* Create a boolean array "prime[0..n]" and initialize
     all entries it as true. A value in prime[i] will
     finally be false if i is Not a prime, else true.*/
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    // Print all prime numbers
    for (int p=2; p<=n; p++)
        if (prime[p])
            printf("%d  \n",p);
}
void SieveOfEratosthenes_parallel(int n)

{
    /* Create a boolean array "prime[0..n]" and initialize
     all entries it as true. A value in prime[i] will
     finally be false if i is Not a prime, else true.*/
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    // Print all prime numbers
    for (int p=2; p<=n; p++)
        if (prime[p])
            printf("%d  \n",p);
}
int main() {
    int n;
    double start_time, end_time;
    printf("Entrer la valeur de N :");
    scanf("%d",&n);
    printf("Following are the prime numbers smaller than or equal to %d \n " ,n);
    start_time = omp_get_wtime();
    SieveOfEratosthenes_sequential(n);
    end_time = omp_get_wtime();
    printf(" sequential time=%f\n",end_time-start_time);
    start_time = omp_get_wtime();
    SieveOfEratosthenes_parallel(n);
    end_time = omp_get_wtime();
    printf(" parallel time=%f\n",end_time-start_time);
    return 0;
}