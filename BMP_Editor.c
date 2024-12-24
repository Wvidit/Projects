#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint8_t* data;

const int Extract_data(FILE* file_ptr);
void Grayscale(unsigned char(*src)[3], FILE* file_ptr, int rows);
float Std_d(uint8_t (*src)[3], int index);

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        fprintf(stderr, "Error: File path not entered.");
        exit(1);
    }

    FILE* ptr;
    ptr = fopen(argv[1], "rb+");
    if(ptr == NULL)
    {
         fprintf(stderr, "Error: File not found.");
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

    //Grayscale(compiled_data, ptr, rows);
    printf("%.2f",Std_d(compiled_data, 19));

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


void Grayscale(uint8_t (*src)[3], FILE* file_ptr, int rows)
{
    //A bit inefficient, ig.
    int m = 18;
    rewind(file_ptr);
    for(int i = 54; i < rows; i++, m++)
    {
        int temp = 0;
        for(int k = 0; k < 3; k++)
            temp += (int)src[m][k];

        for (int j = 0; j < 3; j++)  
            src[m][j] = (uint8_t)(temp/3);
    }

    for( int i = 0; i < rows; i++)
    {
            fwrite( src[i], 1, 3, file_ptr);
    }
}


float Std_d(uint8_t (*src)[3], int index)
{
    float mean;

    for(int i = 0; i < 3; i++)
        mean += src[index][i];
    mean /= 3;

    float std_deviation;
    for(int i = 0; i < 3; i++)
        std_deviation += (int)pow((mean - src[index][i]), 2);
    std_deviation /= 3;
    std_deviation = sqrt(std_deviation);

    return std_deviation;
}
