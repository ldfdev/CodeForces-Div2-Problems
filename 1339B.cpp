#include <bits/stdc++.h>

typedef long long ll;
const int sz = 1e5 + 1;
ll arr[sz], pair_arr[sz];

int main()
{
    int tests;
    ll n, i;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%lld", &n);
        for (i = 1; i <= n; ++i)
            scanf("%lld", arr + i);
        std::sort(arr + 1, arr + 1 + n);
        ll head = 1, tail = n, pos = n;
        while(tail >= head) {
            pair_arr[pos--] = arr[tail--];
            pair_arr[pos--] = arr[head++];
        }
        for (i = 1; i <= n; i++)
            printf("%lld ", pair_arr[i]);
        printf("\n");
    }
    return 0;
}