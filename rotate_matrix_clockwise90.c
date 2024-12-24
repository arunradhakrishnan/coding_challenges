#include <stdio.h>
#include <stdlib.h>


//NOTE THE WAY MATRIX IS ACCESSED .. YOU CANNOT USE 2D arrays!


//PENDEEEEEEEEJO!!!

int* rotateMatrix90Clockwise(int* matrix, int M, int N) {
    // The rotated matrix will have dimensions N x M

    // Allocate memory for the rotated matrix
    int* rotatedMatrix = (int*)malloc(N * M * sizeof(int));

int i,j;
int k,l;


 //[i0][j0]  [i0][j1]  [i0][j2]  [i0][j3] 
 //[i1][j0]  [i1][j1]  [i1][j2]  [i1][j3] 
 //[i2][j0]  [i2][j1]  [i2][j2]  [i2][j3] 
 
// [i0][j0] [i1][j0] [i2][j0]
// [i0][j1] [i1][j1] [i2][j1]
// [i0][j2] [i1][j2] [i2][j2] 
// [i0][j3] [i1][j3] [i2][j3]
 
    // Perform the 90 rotation
    for (i = 0; i < M; i++) {
          for (int j = 0; j < N; j++) {
            //printf(" %2d ",matrix[i*N+j]);
            //printf(" [i%d][j%d] ",i,j);
            int tempx = (M - 1 - i);
            int tempy = (M * j);
            printf(" [%d][%d] ",tempx,tempy);
            rotatedMatrix[tempx + tempy] = matrix[i*N+j];   
        }
        printf("\n");
    }
    printf("\n---------------------\n");

     return rotatedMatrix;
}

// Function to print a matrix
void printMatrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %2d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

// Driver code
int main() {
    int M = 3, N = 4; // Original matrix dimensions

    // Allocate memory for the input matrix
    int* matrix = (int*)malloc(M * N * sizeof(int));


    // Initialize the input matrix
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i * N + j] = i * N + j + 1; // Example values
        }
    }

    printf("Original Matrix (%d x %d):\n", M, N);
    printMatrix(matrix, M, N);

    int newRows, newCols;
    int* rotatedMatrix = rotateMatrix90Clockwise(matrix, M, N);

newRows = N;
newCols = M;

    printf("\nRotated Matrix (90 degrees clockwise) (%d x %d):\n", newRows, newCols);
    printMatrix(rotatedMatrix, newRows, newCols);

    // Free the allocated memory
    // free(matrix);
    // free(rotatedMatrix);

    return 0;
}




// #include <stdio.h>
// #include <stdlib.h>


// //NOTE THE WAY MATRIX IS ACCESSED .. YOU CANNOT USE 2D arrays!


// //PENDEEEEEEEEJO!!!

// int* rotateMatrix90Clockwise(int* matrix, int M, int N) {
//     // The rotated matrix will have dimensions N x M

//     // Allocate memory for the rotated matrix
//     int* rotatedMatrix = (int*)malloc(N * M * sizeof(int));

//     // Perform the 90 rotation
//     for (int i = 0; i < M; i++) {
//         for (int j = 0; j < N; j++) {
//             rotatedMatrix[j * M + (M - 1 - i)] = matrix[i * N + j];
//         }
//     }

//     return rotatedMatrix;
// }

// // Function to print a matrix
// void printMatrix(int* matrix, int rows, int cols) {
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf(" %2d ", matrix[i * cols + j]);
//         }
//         printf("\n");
//     }
// }

// // Driver code
// int main() {
//     int M = 3, N = 4; // Original matrix dimensions

//     // Allocate memory for the input matrix
//     int* matrix = (int*)malloc(M * N * sizeof(int));


//     // Initialize the input matrix
//     for (int i = 0; i < M; i++) {
//         for (int j = 0; j < N; j++) {
//             matrix[i * N + j] = i * N + j + 1; // Example values
//         }
//     }

//     printf("Original Matrix (%d x %d):\n", M, N);
//     printMatrix(matrix, M, N);

//     int newRows, newCols;
//     int* rotatedMatrix = rotateMatrix90Clockwise(matrix, M, N);

// newRows = N;
// newCols = M;

//     printf("\nRotated Matrix (90 degrees clockwise) (%d x %d):\n", newRows, newCols);
//     printMatrix(rotatedMatrix, newRows, newCols);

//     // Free the allocated memory
//     free(matrix);
//     free(rotatedMatrix);

//     return 0;
// }
