#include <bits/stdc++.h>

typedef long long ll;

ll find_suitable_k(const std::unordered_set<ll>& elements) {
    for (ll k = 1; k <= 1024; k++) {
        bool k_is_good = true;
        for (ll elem : elements) {
            if (0 == elements.count(k ^ elem)) {
                k_is_good = false;
                break;
            }
        }
        if (k_is_good)
            return k;
    }
    return -1;
}

int main ()
{
    int tests;
    ll n, i, e;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%lld", &n);
        std::unordered_set<ll> elements (n);
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &e);
            elements.insert(e);
        }
        printf("%lld\n" ,find_suitable_k(elements));
    }
    return 0;
}