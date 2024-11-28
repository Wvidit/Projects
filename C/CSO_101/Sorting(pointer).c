#include <stdio.h>

void sortarray( int * test, int m)
{
    int* ptr1 = test;
    int* ptr2;

    for(int i = 0; i < m-1; i++)
    {
        ptr2 = ptr1 + 1;
        for( int j = i+1; j < m; j++)
        {
            if( *ptr2 < *ptr1)
            {
                swap( ptr1, ptr2);
            }
            ptr2++;
        }
        ptr1++;
    }
    
    ptr1 = NULL;
    ptr2 = NULL;
}

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    printf("Enter array:");
    for( int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sortarray(arr, n);
    for( int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}