#include <bits/stdc++.h>

typedef long long ll;

std::vector<ll> get_bits(ll number) {
    std::vector<ll> bits;
    while(number > 0) {
        bits.push_back(number & 1);
        number >>= 1;
    }
    // std::reverse(bits.begin(), bits.end());
    return bits;
}

int main ()
{
    ll maximum_n = 1e18;
    std::vector<ll> max_number_bits = get_bits(maximum_n);
    std::vector<ll> memoized (max_number_bits.size());
    memoized[0] = 1;
    for (ll i = 1; i < max_number_bits.size(); i++) {
        memoized[i] = (i + 1);
        for (ll j = 0; j < i; j++)
            memoized[i] += memoized[j];
    }
    
    int tests;
    ll n, i, e;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%lld", &n);
        std::vector<ll> bits_of_n = get_bits(n);
        ll solution = 0;
        for (ll i = 0; i < bits_of_n.size(); i++)
            if (bits_of_n[i] == 1)
                solution += memoized[i];
        printf("%lld\n" , solution);
    }
    return 0;
}