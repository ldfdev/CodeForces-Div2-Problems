#include <bits/stdc++.h>

typedef unsigned long long ll;

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int tests;
    std::cin >> tests;
    while(tests--) {
        int n, m, moves = 0;
        char direction;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                std::cin >> direction;
                if ((i == n) && (j == m))
                    continue;
                if (j == m) {
                    if (direction != 'D')
                        ++ moves;
                }
                if (i == n) {
                    if (direction != 'R')
                        ++ moves;
                }
            }
        }
        std::cout << moves << "\n";
    }

    return 0;
}