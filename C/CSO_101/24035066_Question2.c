#include <stdio.h>

void Selectionsort(int temp[], int l)
{
    int small;
    for( int i = 0; i < l; i++)
    {   
        small = i;
        for(int j = i + 1; j < l; j++)
        {
            if(temp[small] > temp[j])
                small = j;
        }
        if( small != i)
        {
            temp[i] = temp[i] ^ temp[small];
            temp[small] = temp[i] ^ temp[small];
            temp[i] = temp[i] ^ temp[small];
        }
    }

    printf("Sorted array:");
    for(int i = 0; i < l; i++)printf("%d", temp[i]);
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

    Selectionsort(arr, n);
}