#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    int* ptr = arr;
    
    for( int i = 0; i < n; i++)
    {
        scanf("%d", ptr);
        ptr++;
    }

    ptr = arr;

    for( int i = 0; i < n; i++)
    {
        printf("%d", *ptr);
        ptr++;
    }

    free(arr);
    arr = NULL;
    ptr = NULL;
}