#include <bits/stdc++.h>

typedef long long ll;

const int MAX_SIZE = 5e3 + 1;
ll persons[MAX_SIZE], chairs[MAX_SIZE];
ll dp[MAX_SIZE][MAX_SIZE];

int main()
{
    ll n {0}, total_persons {0}, total_chairs {0};
    ll occupied {1}, empty {0}, num;
    std::cin >> n;
    for (ll i = 0; i < n; i++) {
        std::cin >> num;
        if (num == occupied) {
            persons[++total_persons] = i;
        }
        else {
            chairs[++total_chairs] = i;
        }
    }
    for (int p = 1; p <= total_persons; p++) {
        for (int c = p; c <= total_chairs; c++) {
            /// if the p person ocupies chair c
            dp[p][c] = dp[p - 1][c - 1] + std::abs(persons[p] - chairs[c]);
            if (c - 1 >= p) {
                dp[p][c] = std::min(dp[p][c],
                                    /// if the chair c remains empty
                                    dp[p][c - 1]);
            }
        }
    }
    std::cout << dp[total_persons][total_chairs] << std::endl;

    return 0;
}