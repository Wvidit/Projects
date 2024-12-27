#include <stdio.h>
#include <stdint.h>
#include "grayscale.h"

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
