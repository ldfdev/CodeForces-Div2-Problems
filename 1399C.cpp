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
        std::vector<ll> w(n);
        for (ll i = 0; i < n; i++) {
            std::cin >> w[i];
        }
        ll best = 1;
        if (n == 1) {
            best = 0;
        }
        else {
            for (ll weight = 2 * n; weight > 1; --weight) {
                ll current_best = 0;
                std::map<int, int> already;
                for (ll j = 0; j < n; j++) {
                    if (already.count(weight - w[j])) {
                        ++current_best;
                        already[weight - w[j]] -= 1;
                        if (already[weight - w[j]] <= 0)
                            already.erase(weight - w[j]);
                    }
                    else {
                        if (already.count(w[j]))
                            already[w[j]] += 1;
                        else
                            already[w[j]] = 1;
                    }
                }
                best = std::max(best, current_best);
            }
        }
        std::cout << best << "\n";
    }

    return 0;
}