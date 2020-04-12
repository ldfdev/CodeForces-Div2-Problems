#include <bits/stdc++.h>

typedef long long ll;
const int length = 1e5 + 1;
ll arr[length];

int main()
{
    int tests;
    scanf("%d", &tests);
    ll n, i, lis;
    while(tests--) {
        lis = 1;
        scanf("%lld", &n);
        for(i = 1; i <= n; ++i) {
            scanf("%lld", &arr[i]);
        }
        std::sort(arr + 1, arr + n + 1);
        for (i = 1; i < n; ++i)
            if (arr[i] != arr[i + 1])
                ++lis;
        printf("%lld\n", lis);
    }
    return 0;
}