#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        int columns=matrix.size()/2;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<columns;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][matrix.size()-j-1];
                matrix[i][matrix.size()-j-1]=temp;
            }
        }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateMatrix(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
