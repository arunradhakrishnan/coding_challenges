#include <iostream>
#include <utility>



class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
    int M = matrix.size();//rows
    int N = matrix[0].size(); //columns


//STEP1: Transpose of the matrix, rows to columns conversion
//STEP1: Transpose of the matrix, rows to columns conversion
//STEP1: Transpose of the matrix, rows to columns conversion
//STEP1: Transpose of the matrix, rows to columns conversion
//STEP1: Transpose of the matrix, rows to columns conversion
//STEP1: Transpose of the matrix, rows to columns conversion
//STEP1: Transpose of the matrix, rows to columns conversion
//STEP1: Transpose of the matrix, rows to columns conversion
//STEP1: Transpose of the matrix, rows to columns conversion

     for(int i = 0; i < M; i++) // index : 0 : 1 : 2
     {
        for(int j = i + 1; j < N; j++) //index 1 2 : 2 
        {
            swap((matrix[i][j]),(matrix[j][i]));
        }
     }

//STEP2: column reverse
//STEP2: column reverse
//STEP2: column reverse
//STEP2: column reverse
//STEP2: column reverse
//STEP2: column reverse
//STEP2: column reverse
//STEP2: column reverse
//STEP2: column reverse
//STEP2: column reverse


//easy reverse operation
// for(int i = 0; i < M; i++)
//     reverse(matrix[i].begin(),matrix[i].end());


    int start = 0;
    int end = M-1;

    while(start < end)
    {
        for(int i = 0; i < M; i++)
        {
            swap(matrix[i][start], matrix[i][end]);
        }
        start++;
        end--;
    }

    }
};