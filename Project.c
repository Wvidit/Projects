#include "stdio.h"
#include "stdlib.h"

unsigned char* data;

const int Extract_data(FILE* file_ptr)
{
    fseek(file_ptr, 0, SEEK_END);
    const int size = ftell(file_ptr);
    rewind(file_ptr);

    data = malloc(size);
    fread(data, 1, size, file_ptr);
    return size;
}

int main()
{
    FILE* ptr;
    ptr = fopen("Untitled.bmp", "rb");
    if(ptr == NULL)
    {
         perror("Error");
         exit(1);
    }

    int rows = (Extract_data(ptr)/3);
    unsigned char (*compiled_data)[3] = malloc((rows) * 3);

    int m = 0;
    for(int i = 54; i < rows;)
    {
        for (int j = 0; j < 3; j++)
        {
            compiled_data[m][j] = data[i];
            i++;
        }
        m++;
    }
    
    free(data);
}