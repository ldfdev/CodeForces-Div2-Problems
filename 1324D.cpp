#include <bits/stdc++.h>

typedef long long ll;

const int max_size = 2 * 1e5 + 1;
ll teacher[max_size], student[max_size], all[max_size];
std::multiset<ll> prev;

int main()
{
    int i, n;
    ll data, good_pairs = 0;
    scanf("%d", &n);

    for (i = 0; i < n; ++i)
        scanf("%lld", teacher + i);
    for (i = 0; i < n; ++i)
        scanf("%lld", student + i);
    for (i = 0; i < n; ++i)
        all[i] = teacher[i] - student[i];
    std::sort(all, all + n);

    for (i = 1; i < n; ++i) {
        data = -all[i] + 1;
        ll dist = std::distance(std::lower_bound(all, all + i, data), all + i);
        good_pairs += dist;
        // printf(" found distance %lld\n", dist);
    }

    printf("%lld\n", good_pairs);
    return 0;
}