#include <stdio.h>

int max(int set[], int a);

int main()
{
    printf("Enter size of array:");
    int n; scanf("%d",&n);

    int arr[n];
    printf("Enter array:");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Max of the array is %i.",max( arr, n));
}

int max(int set[], int a)
{
    int ref = set[0];

    for( int i = 1; i < a; i++)
    {
        if( ref <= set[i])
        {
            ref = set[i];
        }
    }

    return ref;
}