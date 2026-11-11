#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangleI(int r) {
    vector<vector<int>> pascal;

    for (int i = 0; i < r; i++) {
        vector<int> row(i+1);
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                row[j] = 1;
            } else {
                row[j] =
                    pascal[i-1][j - 1] +
                    pascal[i-1][j];
            }
        }
        pascal.push_back(row);
    }

    return pascal;
}

int main() {
    int r = 4;

    vector<vector<int>> ans = pascalTriangleI(r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
