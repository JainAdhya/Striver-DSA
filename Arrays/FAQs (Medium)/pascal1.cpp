#include <bits/stdc++.h>
using namespace std;

int pascalTriangleI(int r, int c) {
    vector<vector<int>> pascal(2, vector<int>(r, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                pascal[i % 2][j] = 1;
            } else {
                pascal[i % 2][j] =
                    pascal[(i + 1) % 2][j - 1] +
                    pascal[(i + 1) % 2][j];
            }
        }
    }

    return pascal[(r - 1) % 2][c - 1];
}

int main() {
    int r = 4;
    int c = 2;

    int ans = pascalTriangleI(r, c);
    cout << ans;

    return 0;
}
