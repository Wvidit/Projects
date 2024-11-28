#include<stdio.h>

int main()
{
    FILE *file;
    file = fopen("Source.txt", "r");

    int n;
    char *temp;
    fscanf(file, "%s", temp);
    scanf("%d", &n);
    file = fopen("Source.txt", "w");

    for( int i = 0; i < strlen(temp); i++)
    {
        if(i != n)
            fprintf(file, "%c", temp[i]);
        else
            fprintf(file, "%c", 'd');
            fprintf(file, "%c", temp[i]);
    }

    fclose(file);
}