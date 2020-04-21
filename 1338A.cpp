#include <bits/stdc++.h>

typedef long long ll;

const int sz = 1e5 + 1;
ll arr[sz];

struct ecart {
    ll max, min;
};

int main()
{
    int n, tests, i, j;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%lld", arr + i);
        ecart absolute({arr[1], arr[1]}), current({arr[1], arr[1]});
        for (i = 1; i <= n; i++) {
            current.min = std::min(arr[i], current.min);
            absolute.max = std::max(absolute.max, arr[i]);
            if (absolute.max == arr[i])
                absolute.min = arr[i]; // reset
            absolute.min = std::min(absolute.min, arr[i]);
            if (absolute.max - absolute.min > current.max - current.min)
                current = absolute;
        }
        // printf("Max followed by min pair %lld, %lld\n", current.max, current.min);
        ll days = 0;
        while (current.max - current.min > pow(2, days) - 1)
            ++days;
        printf("%lld\n", days);
    }
    return 0;
}