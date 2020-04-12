#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    ll u, v;
    scanf("%lld %lld", &u, &v);
    if (u == v) {
        if (u == 0)
            printf("0\n");
        else
            printf("1\n%lld\n", u);
    }
    else if (u > v)
        printf("-1\n");
    else if ((v - u) & 1)
        printf("-1\n");
    else {
        ll x = (v - u) >> 1;
        if (u & x)
            printf("3\n%lld %lld %lld\n", u, x, x);
        else
            printf("2\n%lld %lld\n", u + x, x);
    }
    return 0;
}