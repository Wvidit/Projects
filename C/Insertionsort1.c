#include<stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int arr[] = { 2, 5 ,3 ,4};
    
    for(int i = 0; i < 4; i++)
    {
        int j = i - 1;
        while(j >= 0 && arr[j] > arr[i])
        {
            swap(&arr[i], &arr[j]);
            j--;
            i--;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        printf("%d", arr[i]);
    }
}