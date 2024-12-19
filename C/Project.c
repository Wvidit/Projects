#include "stdio.h"
#include "stdlib.h"

int main()
{
    FILE* ptr;
    int temp;
    ptr = fopen("C:/Users/VIDIT/OneDrive/Desktop/Untitled.bmp", "r");
    fscanf(ptr, "%d", &temp);
    printf("%d", temp);

}