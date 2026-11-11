#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int r : row) {
    for (int j = 0; j < matrix[0].size(); j++) {
        matrix[r][j] = 0;
    }
}
        for (int c : col) {
    for (int j = 0; j < matrix.size(); j++) {
        matrix[j][c] = 0;
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
