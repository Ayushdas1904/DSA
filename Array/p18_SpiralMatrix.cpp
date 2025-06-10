#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n));
        int count = 0, total = n*n;
        int rowStart = 0, colStart = 0, rowEnd = n-1, colEnd = n -1;
        int num = 1;
        while(count<total){
            for(int index= colStart; index <= colEnd ; index++){
                matrix[rowStart][index] = num;
                num++;
                count++;
            }
            rowStart++;

            for(int index= rowStart; index <= rowEnd ; index++){
                matrix[index][colEnd] = num;
                num++;
                count++;
            }

            colEnd--;

            for(int index= colEnd; index >= colStart ; index--){
                matrix[rowEnd][index] = num;
                num++;
                count++;

            }
            rowEnd--;

            for(int index= rowEnd; index >= rowStart ; index--){
                matrix[index][colStart] = num;
                num++;
                count++;
            }
            colStart++;
        }

        return matrix;

    }