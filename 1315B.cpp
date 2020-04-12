#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    int tests, a, b, p;
    std::string s;
    std::cin >> tests;
    while(tests--) {
        std::cin >> a >> b >> p >> s;
        std::vector<ll> costs(s.size());
        for (ll i = s.size() - 2; i > -1; --i) {
            ll cost = a;
            if (s[i] == 'B')
                cost = b;
            if (i == s.size() - 2)
                costs[i] = cost;
            else {
                costs[i] = costs[i + 1];
                if (s[i] != s[i + 1])
                    costs[i] += cost;
            }
        }
        for (ll i = 0; i < s.size(); ++i) {
            if (p >= costs[i]) {
                std::cout << 1 + i << std::endl;
                break;
            }
        }
    }
    return 0;
}