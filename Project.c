#include "stdio.h"
#include "stdlib.h"

unsigned char* data;

const int Extract_data(FILE* file_ptr);
void Grayscale(unsigned char(*src)[3], FILE* file_ptr, int rows);

int main()
{
    FILE* ptr;
    ptr = fopen("Untitled.bmp", "rb+");
    if(ptr == NULL)
    {
         perror("Error");
         exit(1);
    }

    int rows = (Extract_data(ptr)/3);
    unsigned char (*compiled_data)[3] = malloc((rows) * 3);

    int m = 0;
    for(int i = 0; i < rows;)
    {
        for (int j = 0; j < 3; j++)
        {
            compiled_data[m][j] = data[i];
            i++;
        }
        m++;
    }
    for(int i = 0; i , rows; i++)
    {
      if(m % 1000 == 0)
            {    printf("%d",compiled_data[m][k]);
                if(compiled_data[m][k] == 0)
                    printf("(%d,%d)", m,k);
            }
    }
    printf("%d\n", m);
    printf("%d\n", rows);
    rewind(ptr);
    printf("%d",ftell(ptr));
    Grayscale(compiled_data, ptr, rows);

    free(compiled_data);
    free(data);
}

const int Extract_data(FILE* file_ptr)
{
    fseek(file_ptr, 0, SEEK_END);
    const int size = ftell(file_ptr);
    rewind(file_ptr);

    data = malloc(size);
    fread(data, 1, size, file_ptr);
    return size;
}

void Grayscale(unsigned char (*src)[3], FILE* file_ptr, int rows)
{
    //A bit inefficient, ik.
    int m = 18;
    for(int i = 54; i < rows; i++)
    {
        int temp = 0;
        for(int k = 0; k < 3; k++)
        {
            temp += (int)src[m][k];
           
        }

        for (int j = 0; j < 3; j++)
        {   
            src[m][j] = (unsigned char)(temp/3);
           
        }
        if(m % 1000 == 0)
            printf("\n");
        m++;
    }

    /*for( int i = 18; i < rows; i++)
    {
        for( int j = 0; j < 3; j++)
            fwrite(src[i][j], 1, 1, file_ptr);
    }*/
}