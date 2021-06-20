#include<bits/stdc++.h>

typedef long long ll;

const ll _MAX_SIZE = 2e3;
ll arr[_MAX_SIZE], odd[_MAX_SIZE];

ll gcd(ll a, ll b) {
    ll new_a, new_b;
    if (a < b)
        return gcd(b, a);
    while (b > 0) {
        new_a = b; new_b = a % b;
        a = new_a; b = new_b;
    }
    return a;
}

ll solve() {
    ll n, odd_index = 0;
    std::cin >> n;
    for (ll i = 0; i < n; i++) {
        std::cin >> arr[i];
        if (arr[i] & 1)
            odd[odd_index++] = arr[i];
    }
    ll result = n * (n - 1) / 2 - odd_index * (odd_index - 1) / 2;
    for (ll i = 0; i < odd_index; i++) {
        for (ll j = i + 1; j < odd_index; j++) {
            if (gcd(odd[i], odd[j]) > 1)
                result += 1;
        }
    }
    return result;
}


int main() {
    ll tests;
    std::cin >> tests;
    for (ll test = 0; test < tests; test++)
        std::cout << solve() << "\n";
    return 0;
}