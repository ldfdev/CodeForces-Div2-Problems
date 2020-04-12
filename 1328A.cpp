#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    int tests;
    ll a, b;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%lld %lld", &a, &b);
        a = a % b;
        if (a == 0)
            printf("0\n");
        else
            printf("%lld\n", (b - a));
    }
    return 0;
}