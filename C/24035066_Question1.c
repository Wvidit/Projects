#include<stdio.h>

int Linearsearch(int brr[], int m)
{
    int target;
    printf("Enter integer to search for:");
    scanf("%d", &target);

    for(int i = 0; i < m; i++)
    {
        if(brr[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    printf("Enter length of array:");
    int n;
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array:");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", Linearsearch(arr, n));
}