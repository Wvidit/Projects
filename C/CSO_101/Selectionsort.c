#include<stdio.h>

int minimum(int arr[], int start, int end)
{
    int temp = arr[start], t = start;
    for(int i = start; i <= end; i++)
    {
        if(arr[i] < temp)
        {    t = i;
            temp = arr[i];}
    }
    return t;
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[] = {2, 5, 6, 3};
    for(int i = 0; i < 4; i++)
    {
        for(int j = i; j < 4; j++)
        {
            int min = minimum(arr, i, j);
            swap(&arr[i], &arr[min]);
        }
    }
    for(int i = 0; i < 4; i++)
    {
        printf("%d", arr[i]);
    }
}