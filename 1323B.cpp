#include <bits/stdc++.h>

using namespace std;

const int s = 40001;

int main()
{
    long long a[s], b[s], m, n, i, j, k, subrectangles = 0, side1, side2;
    scanf("%lld %lld %lld", &n, &m, &k);
    a[0] = 0; b[0] = 0;
    for(i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for(i = 1; i <= m; ++i) {
        scanf("%lld", &b[i]);
        b[i] += b[i - 1];
    }
    vector<pair<int, int>> kpairs;
    for(i = 1; i <= n; ++i) {
        j = k / i;
        if (i * j == k)
            kpairs.push_back(make_pair(i - 1, j - 1));
    }
    for(auto ab : kpairs) {
        side1 = 0;
        for(i = 1; i + ab.first <= n; ++i)
            if (a[i + ab.first] - a[i - 1] == ab.first + 1)
                ++side1;
        side2 = 0;
        for(i = 1; i + ab.second <= m; ++i)
            if (b[i + ab.second] - b[i - 1] == ab.second + 1)
                ++side2;
        subrectangles += side1 * side2;
    }
    printf("%lld\n", subrectangles);
    return 0;
}