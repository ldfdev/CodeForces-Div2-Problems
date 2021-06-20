#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

int n, m;
int matrix[500][500], matrix2[500][500];

void print_row(int row) {
    for (int l = 0; l < m; l++) {
        std::cout << matrix[row][l] << " ";
    }
    std::cout << "\n";
}

void solve() {
    std::cin >> n >> m;
    std::unordered_map<int, int> d;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            std::cin >> matrix[row][col];
        }
        d[matrix[row][0]] = row;
    }
    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n; row++) {
            std::cin >> matrix2[col][row];
        }
            // std::cout << "reading column " << col << ": ";
            // for (int row = 0; row < n; row++) {
            //     std::cout << matrix2[col][row] << " ";
            // }
            // std::cout << "\n";
        if (d.find(matrix2[col][0]) == d.end()) {
            continue;
        }
        
        for (int l = 0; l < n; l++) {
            print_row(d[matrix2[col][l]]);
        }
    }
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int tests;
    std::cin >> tests;
    while(tests--) {
        solve();
    }
    return 0;
}