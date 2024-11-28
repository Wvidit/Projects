#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE* src, *odd, *even;
    src = fopen("C:/Users/VIDIT/OneDrive/Desktop/Codes(local)/Source.txt", "r");
    odd = fopen("C:/Users/VIDIT/OneDrive/Desktop/Codes(local)/Odd.txt", "w");
    even = fopen("C:/Users/VIDIT/OneDrive/Desktop/Codes(local)/Even.txt", "w");

    int *temp = (int*)malloc(100);
    while(fscanf(src, "%d", temp) != EOF)
    {
        printf("%d\n", *temp);
        if((*temp) % 2 == 0)
            fprintf(even, "%d", *temp);
        else
            fprintf(odd, "%d", *temp);
    }

    free(temp);
    fclose(src);
    fclose(odd);
    fclose(even);
}