#include<stdio.h>

int BinarySearch(int len, int arr[], int target);

int main()
{
    int n, tar;
    printf("Enter size of array:");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter no. to search for:");
    scanf("%d", &tar);

    return BinarySearch(n, arr, tar);
}

int BinarySearch(int len, int arr[], int target)
{
    int low = 0, high = len-1;
    
    while( low <= high)
    {
        int mid = (high + low)/2;

        if(arr[mid] == target)
            return mid;

        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 2;
}      