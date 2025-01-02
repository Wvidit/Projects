#include <stdio.h>
#include <stdint.h>
#include "noise.h"

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
    
    for(int i = 55; i < rows; i++)
    {
            for(int j = 0; j < 3; j++)
            {
                random = rand();
                if(random % 2 == 0 && src[i][j] < 204)
                    noisey[i][j] = (uint8_t)(src[i][j] + 50);
                if(random % 2 != 0 && src[i][j] > 40)
                    noisey[i][j] = (uint8_t)(src[i][j] - 400);
            }
    } 

    for( int i = 0; i < rows; i++)
    {
        if(fwrite( noisey[i], 1, 3, file_ptr) != 3)
        {
            printf("Error while writing.");
            return;
        }
    } 
    free(noisey);
}
