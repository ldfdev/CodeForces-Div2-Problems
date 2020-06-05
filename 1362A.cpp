#include <bits/stdc++.h>

typedef long long ll;

ll compute_steps(ll a, ll b) {
    if (a > b)
        return compute_steps(b, a);
    long long ops = 0, q, d = b / a;
    if (a * d != b)
        return -1;
    if (0 != (d & (d - 1)))
        return -1;
    for (long long rem : {3, 2, 1})
    {
        ll exponent = (1 << rem);
        while (exponent <= d)
            exponent <<= rem;
        exponent >>= rem ;
        // printf("Analysing quot %lld with exponent %lld\n", d, exponent);
        if (exponent == 1)
            continue;
        ll exponent2 = exponent, q = 0;
        while(exponent2 > 1) {
            ++q;
            exponent2 >>= rem; 
        }
        ops += q;
        d >>= (q * rem);
    }
    return ops;
}

int main ()
{
    int tests;
    ll a, b, ops;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%lld %lld", &a, &b);
        if (a == b) {
            ops = 0;
        }
        else {
            ops = compute_steps(a, b);
        }
        printf("%lld\n", ops);
    }
    return 0;
}