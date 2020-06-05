#include <bits/stdc++.h>

int main()
{
    int tests;
    long long cost, x, y, a, b;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
        if (x < y)
            std::swap(x, y);
        cost = (x - y) * a;
        if (b > 2 * a)
            cost += y * 2 * a;
        else
            cost += y * b;
        printf("%lld\n", cost);
    }
    return 0;
}