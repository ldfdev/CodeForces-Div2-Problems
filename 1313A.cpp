#include <bits/stdc++.h>

std::set<int> configurations;

int solve(int a, int b, int c) {
    if (a + b + c == 0)
        return 0;

    int best_score = 0;
    int bit[3];
    for(int cnf = 1; cnf < 8; ++cnf) {
        if (configurations.count(cnf))
            continue;
        std::fill(bit, bit + 3, 0);
        for (int b = 0; b < 3; ++b) {
            if (cnf & (1 << b))
                bit[b] = 1;
        }
        if ((a - bit[0] >= 0) && (b - bit[1] >= 0) && (c - bit[2] >= 0)) {
            configurations.insert(cnf);
            int score = 1 + solve(a - bit[0], b - bit[1], c - bit[2]);
            best_score = std::max(best_score, score);
            configurations.erase(cnf);
        }
    }

    return best_score;
}

int main()
{
    int tests, i;
    std::cin >> tests;
    while(tests--) {
        configurations.clear();
        std::vector<int> abc(3);
        for(i = 0; i < 3; ++i) {
            std::cin >> abc[i];
            if (abc[i] > 4)
                abc[i] = 4;
        }
        std::cout << solve(abc[0], abc[1], abc[2]) << std::endl;
    }
    return 0;
}