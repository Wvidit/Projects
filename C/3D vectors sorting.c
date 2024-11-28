#include <stdio.h>
#include<stdlib.h>
#include <math.h>

typedef struct {
    int x, y, z;
    int mod;
}vector;

int modulus(vector v)
{
    return (int)sqrt((int)pow(v.x,2) + (int)pow(v.y,2) + (int)pow(v.z,2));
}

void swap(int *a, int *b)
{
    int* temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);

    vector* some = (vector*)malloc(n * 4 * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        printf("Enter vectors for x, y, z:");
        scanf("%d %d %d", &some[i].x, &some[i].y, &some[i].z);
        some[i].mod = modulus(some[i]);
    }

    for( int j = 0; j < n; j++)
    {
        for(int m = 0 ; m < n; m++)
        {
            if(some[m].mod > some[m+1].mod)
            {
                swap(&some[m].mod, &some[m+1].mod);
                swap(&some[m].x, &some[m+1].x);
                swap(&some[m].y, &some[m+1].y);
                swap(&some[m].z, &some[m+1].z);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("Sorted vectors for x, y, z:");
        printf("%d %d %d \n %d", some[i].x, some[i].y, some[i].z, some[i].mod);
    }
}