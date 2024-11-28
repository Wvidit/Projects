#include <stdio.h>

int fact(int num);
int k = 1;
int main()
{
    int n;

    printf("Enter a no.");
    scanf("%d", &n); 
    if( n < 0)
    {
        printf("Enter a valid number.");
    }
    else
    {
        printf("Factorial of the number is %d.",fact(n));
    }
}

int fact(int num)
{
    if(num > 1)
    {
        k *= num;
        num--;
        fact(num);
    }
    else
    {
        return k;
    }
}