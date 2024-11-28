//Base logic of 2D matrices

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows;
    int cols;
    
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) 
    {
        free(matrix[i]); 
    }
    free(matrix);
    return 0;
}
