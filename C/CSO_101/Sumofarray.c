#include <stdio.h>

int sum(int set[], int a);

int main()
{
    printf("Enter length of array:");
    int n; scanf("%d",&n);
    printf("Enter array:");
    int arr[n];
    for( int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Sum of array is %d.", sum( arr, n));
    return 0;
}

int sum(int set[], int a)
{
    int su = 0;
    for( int i = 0; i < a; i++)
    {
        su = su + set[i];
    }
    return su;
}