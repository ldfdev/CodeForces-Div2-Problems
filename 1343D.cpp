#include <bits/stdc++.h>

const int sz = 1 + 2e5;
int n, k, i;
long arr[sz], dp[sz];

int changes(long target, int index) {
    if (target == arr[index] + arr[n + 1 - index])
        return 0;
    if (target <= arr[index])
        return 2;
    if (target <= k + arr[n + 1 - index])
        return 1;
    return 2;
}

struct comp 
{
    bool operator() (const std::pair<long, long>& p1, const std::pair<long, long>& p2) const
    {
        if (p1.first == p2.first)
            // when querying {x, 0} to have already counted values as {x - y, *}, {x, y>0} before {x, 0}
            return (p1.second < p2.second);
        return (p1.first < p2.first);
    }
};

int main()
{
    int tests;
    long actual_cost, lower, greater, within, eq, payload, score;
    scanf("%d", &tests);
    while(tests--) {
        std::vector<std::pair<long, long>> shao;
        std::vector<int> da;
        std::map<long, long> eq_map;
        scanf("%d%d", &n, &k);
        shao.reserve(n / 2);
        da.reserve(n / 2);
        for(i = 1; i <= n; i++)
            scanf("%ld", arr + i); 
        for(i = 1; (i * 2) <= n; i++) {
            if (arr[i] > arr[n + 1 - i])
                std::swap(arr[i], arr[n + 1 - i]);
            shao.emplace_back(std::make_pair(arr[i], arr[n + 1 - i]));
            da.emplace_back(arr[n + 1 - i]);
            payload = arr[i] + arr[n + 1 - i];
            if (eq_map.count(payload))
                ++eq_map[payload];
            else
                eq_map[payload] = 1;
        }
        std::sort(shao.begin(), shao.end(), comp());
        std::sort(da.begin(), da.end());
        long best_solution = -1;
        // printf("Sorted pairs\n");
        // for(decltype(shao)::iterator it = shao.begin(); it != shao.end(); ++it)
        //     printf("   %ld -> %ld\n", it->first, it->second);
        for(payload = 2; payload <= 2 * k; ++payload) {
            // payload = it->first + it->second;
            eq = eq_map[payload];
            lower = std::distance(std::upper_bound(shao.begin(), shao.end(), std::make_pair(payload, 0L)), shao.end());
            // payload is lower than lower elements out of n
            greater = std::distance(da.begin(), std::lower_bound(da.begin(), da.end(), payload - k));
            // payload is greater than greater elements out of n
            within = n / 2 - lower - eq - greater;
            score = 2 * lower + 2 * greater + within;
            if (best_solution == -1)
                best_solution = score;
            best_solution = std::min(best_solution, score);
            // printf("  If solution were %ld: less %ld| greater %ld| eq %ld| between %ld| counting %ld\n",
            //     payload, lower, greater, eq, within, score);
        }
        printf("%ld\n", best_solution);
    }
    return 0;
}