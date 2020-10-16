#include <bits/stdc++.h>

typedef long long ll;

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
        std::vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            std::cin >> b[i];
        }
        ll A, B, cost = 0, a_temp, b_temp;
        A = *std::min_element(a.begin(), a.end());
        B = *std::min_element(b.begin(), b.end());
        for (ll i = 0; i < n; i++) {
            a_temp = a[i] - A;
            b_temp = b[i] - B;
            cost += a_temp + b_temp - std::min(a_temp, b_temp);
        }
        std::cout << cost << "\n";
    }

    return 0;
}