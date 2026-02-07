#include <stdio.h>

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n, result;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    result = fib(n);

    printf("The %dth Fibonacci number is: %d\n", n, result);

    return 0;
}