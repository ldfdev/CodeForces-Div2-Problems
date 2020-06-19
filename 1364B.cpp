#include <bits/stdc++.h>
#define long long int;

const int sz = 1e5 + 1;
int perm[sz], good[sz];

void solve() {
    int n, i, good_idx = 0, a, b, c;
    std::cin >> n;
    for (i = 0; i < n; i++)
        std::cin >> perm[i];
    if (n == 2) {
        std::cout << n << "\n";
        std::cout << perm[0] << " " << perm[1] << "\n";
        return;
    }
    good[good_idx] = perm[0];
    for (i = 1; i + 1 < n; i++) {
        if ((good[good_idx] < perm[i]) && (perm[i] < perm[i + 1]))
            continue;
        if ((good[good_idx] > perm[i]) && (perm[i] > perm[i + 1]))
            continue;
        good[++good_idx] = perm[i];
    }
    good[++good_idx] = perm[n - 1];
    std::cout << (1 + good_idx) << "\n";
    for (i = 0; i <= good_idx; i++)
        std::cout << good[i] << " ";
    std::cout << "\n";
}

int main()
{
    int tests;
    std::cin >> tests;
    while(tests--) {
        solve();
    }
    return 0;
}