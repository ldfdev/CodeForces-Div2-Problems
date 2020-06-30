#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.sync_with_stdio(false);

    ll tests;
    std::cin >> tests;
    while(tests--) {
        ll n;
        std::cin >> n;
        std::vector<ll> bad(n, 0);
        std::string s;
        std::cin >> s;
        std::stack<ll> q;
        for (ll i = 0; i < n; i++) {
            bad[i] = 1;
            if (s[i] == '(')    {
                q.push(i);
            }
            else if (q.size() > 0) {
                bad[i] = 0;
                bad[q.top()] = 0;
                q.pop();
            }
        }
        ll bads = 0;
        for (ll i = 0; i < n; i++) {
            if (bad[i] == 1)
                ++bads;
        }
        std::cout << (bads >> 1) << "\n";
    }
    return 0;
}