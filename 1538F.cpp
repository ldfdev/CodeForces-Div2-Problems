#include <bits/stdc++.h>

typedef long long ll;

const ll sizemax = 10;
std::unordered_map<ll, ll> dp;
ll arr[sizemax + 1];

ll digit_changes(ll upper) {
    //digit changes from 1 to upper inclusive range
    // std::cout << "digits of " << upper << ": ";
    ll index = 0;
    while (upper > 0) {
        arr[index++] = upper - 10 * (ll)(upper / 10);
        upper = upper / 10;
    }
    // for (ll i = 0; i < index; i++)
    //     std::cout << arr[i] << ",";
    // std::cout << "\n";
    ll changes = arr[0]; // smallest num is 1 so drop the change from 0 to 1
    for (ll i = 1; i < index; i++) {
        changes += dp[i] * arr[i];
    }
    return changes;
}

int main()
{
    // fast input
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll l, r;
    // precompute
    dp[1] = 11;
    for (int i = 2; i < sizemax; i++) {
        dp[i] = 10 * dp[i - 1] + 1;
    }
    int tests;
    std::cin >> tests;
    for(int test = 1; test <= tests; test++) {
        std::cin >> l >> r;
        std::cout << digit_changes(r) - digit_changes(l) << "\n";
        // std::cout << "test " << test << " >> " << digit_changes(test) << "\n";
    }
    return 0;
}