#include <bits/stdc++.h>

typedef long long ll;

ll n, k, arr;
const ll sz = 1 + 1e9;

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.sync_with_stdio(false);

    ll tests;
    std::cin >> tests;
    while(tests--) {
        std::cin >> n >> k;
        std::map<ll,ll> rems;
        // maximum remainder and number of elements that give maximum remainder
        ll max_remainder = 0, cnt_max_rem = 0;
        for (ll i = 1; i <= n; i++) {
            std::cin >> arr;
            ll rem = k - arr % k;
            if (rem == k)
                continue;
            if (rems.count(rem))
                ++rems[rem];
            else
                rems[rem] = 1;
            
            if (cnt_max_rem == 0) {
                max_remainder = rem;
                cnt_max_rem = rems[rem];
            }
            if (rems[rem] > cnt_max_rem) {
                max_remainder = rem;
                cnt_max_rem = rems[rem];
            }
            if (rems[rem] == cnt_max_rem) {
                max_remainder = std::max(max_remainder, rem);
            }
        }
        
        std::cout << std::max(0ll, (cnt_max_rem - 1) * k + max_remainder + 1) << "\n";
    }
    return 0;
}