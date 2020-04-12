#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    int tests;
    scanf("%d", &tests);
    ll x, a, b, ab, d, i;
    while(tests--) {
        scanf("%lld", &x);
        for(i = 1; i <= x; ++i) {
            if (x != i * (x / i))
                continue;
            ab = x / i - 1;
            printf("%lld %lld\n", i, i * ab);
            break;
        }
    }
    return 0;
}