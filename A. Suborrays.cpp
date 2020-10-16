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
        int n;
        std::cin >> n;
        for (int i = 1; i < n; i++)
            std::cout << i << " ";
        std::cout << n << "\n";
    }

    return 0;
}