#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "grayscale.h"
#include "noise.h"
#define PI 3.14

uint8_t* data;

const int Extract_data(FILE* file_ptr);

void Add_noise(uint8_t (*src)[3], FILE *file_ptr, int rows);

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        fprintf(stderr, "Error: File path not entered.\n");
        exit(1);
    }

    FILE* ptr;
    ptr = fopen(argv[1], "rb+");
    if(ptr == NULL)
    {
         fprintf(stderr, "Error: File not found.\n");
         exit(2);
    }

    int rows = (Extract_data(ptr)/3);
    uint8_t (*compiled_data)[3] = malloc((rows) * 3);

    int m = 0;
    for(int i = 0; i < rows; m++, i++)
    {
        for (int j = 0; j < 3; j++)
        {
            compiled_data[m][j] = data[m*3 + j];
        }
    }
    
    Grayscale(compiled_data, ptr, rows);
    rewind(ptr);
    Add_noise(compiled_data, ptr, rows);

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
