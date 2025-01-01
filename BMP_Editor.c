#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include "grayscale.h"
#define PI 3.14

uint8_t* data;

const int Extract_data(FILE* file_ptr);

//void Grayscale(unsigned char(*src)[3], FILE* file_ptr, int rows);

float Std_d(uint8_t (*src)[3], int index);

float mean(uint8_t (*src)[3], int index);

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
    //printf("%d", rows);
    //Grayscale(compiled_data, ptr, rows);
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

float Std_d(uint8_t (*src)[3], int index)
{    

    int Mean = mean(src, index);

    float std_deviation;
    for(int i = 0; i < 3; i++)
        std_deviation += (int)pow((Mean - src[index][i]), 2);
    std_deviation /= 3;
    std_deviation = sqrt(std_deviation);

    return std_deviation;
}


float mean(uint8_t (*src)[3], int index)
{
    float mean;
    for(int i = 0; i < 3; i++)
        mean += src[index][i];
    mean /= 3;

    return mean;
}


void Add_noise(uint8_t (*src)[3], FILE *file_ptr, int rows)
{
    int random;
    uint8_t (*noisey)[3] = malloc(rows*3);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            noisey[i][j] = src[i][j];
        }
    }
    
    for(int i = 54; i < rows; i++)
    {
            for(int j = 0; j < 3; j++)
            {
                random = rand();
                if(random % 2 == 0 && src[i][j] < 244)
                    noisey[i][j] = (uint8_t)(src[i][j] + 10);
                if(random % 2 != 0 && src[i][j] > 10)
                    noisey[i][j] = (uint8_t)(src[i][j] - 10);
                if( i % 10000 == 0)
                    printf("%d\n", random);
            }
    } 
    for( int i = 0; i < rows; i++)
    {
            fwrite( noisey[i], 1, 3, file_ptr);
    } 
}