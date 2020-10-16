#include <bits/stdc++.h>

typedef unsigned long long ll;

const ll modulus = 7 + 1e9;

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int tests;
    std::cin >> tests;
    while(tests--) {
        ll m, n;
        std::cin >> n >> m;
        if ((n > 3) && (m > 3))
            std::cout << "-1\n";
        else if (n == 1)
            std::cout << "0\n";
        else if (m == 1)
            std::cout << "0\n";
        else {

        }
    }

    return 0;
}