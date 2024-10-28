#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // Allocate memory for the matrix
    int** matrix = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
    }
    
    int startingRow = 0;
    int endingRow = n - 1;
    int startingCol = 0;
    int endingCol = n - 1;
    
    int currentValue = n;
    
    // Fill the matrix in concentric layers
    while (startingRow <= endingRow && startingCol <= endingCol) {
        // Fill the top row
        for (int j = startingCol; j <= endingCol; j++) {
            matrix[startingRow][j] = currentValue;
        }
        startingRow++;
        
        // Fill the right column
        for (int i = startingRow; i <= endingRow; i++) {
            matrix[i][endingCol] = currentValue;
        }
        endingCol--;
        
        // Fill the bottom row
        for (int j = endingCol; j >= startingCol; j--) {
            matrix[endingRow][j] = currentValue;
        }
        endingRow--;
        
        // Fill the left column
        for (int i = endingRow; i >= startingRow; i--) {
            matrix[i][startingCol] = currentValue;
        }
        startingCol++;
        
        // Move to the next layer
        currentValue--;
    }
    
    // Print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}