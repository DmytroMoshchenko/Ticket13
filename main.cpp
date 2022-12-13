#include <iostream>

void processMatrix(int** matrix, int r, int c);

int main() {
    // Create a 2D array
    int** matrix = new int* [3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new int[3];
    }
    // Fill the array with values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i + j;
        }
    }
    // Print the array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    // Process the array
    processMatrix(matrix, 3, 3);
    // Print the array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Delete the array
    for (int i = 0; i < 3; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}

void processMatrix(int** matrix, int r, int c) {
    for (int i = 0; i < c; i++) {
        int max = matrix[0][i];
        int min = matrix[0][i];
        int maxIndex = 0;
        int minIndex = 0;
        for (int j = 0; j < r; j++) {
            if (matrix[j][i] > max) {
                max = matrix[j][i];
                maxIndex = j;
            }
            if (matrix[j][i] < min) {
                min = matrix[j][i];
                minIndex = j;
            }
        }
        matrix[maxIndex][i] = min;
        matrix[minIndex][i] = max;
    }
}