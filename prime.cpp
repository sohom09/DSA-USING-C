#include <stdio.h>
int isPrime(int num)
 {
    if (num == 1 || num == 0)
        return 0; 
    for (int i = 2; i<num; i++) {
        if (num % i == 0)
            return 0; 
    }
    return 1; 
}

int main() 
{
    int lower, upper;
    printf("Enter lower bound of the interval: ");
    scanf("%d", &lower);
    printf("Enter upper bound of the interval: ");
    scanf("%d", &upper);

    printf("Prime numbers between %d and %d are: ", lower, upper);
    for (int i = lower; i <= upper; ++i) {
        if (isPrime(i))
            printf("%d ", i);
    }

    return 0;
}

