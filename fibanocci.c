#include <stdio.h>


int Fib(int n)
{
    if (n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return Fib(n-1)+Fib(n-2);
}

int main()
{
    int n, fib_n;
    scanf("%d",&n);
    fib_n=Fib(n);
    printf("Fibonacci of %d th number: %d\n", n, fib_n);
}

