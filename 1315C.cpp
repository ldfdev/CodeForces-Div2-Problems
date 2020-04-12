#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    int tests;
    std::cin >> tests;
    while(tests--) {
        ll s = 0;
        int n, i;
        std::cin >> n;
        std::vector<int> b(n + 1), a(2 * n + 1);
        std::set<ll> used;
        for (i = 1; i <= n; ++i) {
            std::cin >> b[i];
            a[2 * i - 1] = b[i];
            used.insert(b[i]);
        }
        
        for (i = 1; i <= n; ++i) {
            ll a2i = b[i] + 1;
            while(used.count(a2i))
                ++a2i;
            a[2 * i] = a2i;
            used.insert(a2i);
        }
        // std::cout << ">>> ";
        for (i = 1; i <= 2 * n; ++i) {
            s += a[i];
            // std::cout << a[i] << " ";
        }
        // std::cout << std::endl;
        if (s != n * (2 * n + 1))
            std::cout << -1 << std::endl;
        else {
            for (i = 1; i <= 2 * n; ++i)
                std::cout << a[i] << " ";
            std::cout << std::endl;
        }
    }
    return 0;
}