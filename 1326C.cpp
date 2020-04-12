#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll mod = 998244353;
const int ss = 1 + 2e5;
int p[ss], bak[ss];
int main()
{
    int i, k, n;
    scanf("%d %d", &n, &k);
    for(i = 1; i <= n; ++i) {
        scanf("%d", p + i);
        bak[i] = p[i];
    }
    sort(bak + 1, bak + 1 + n, greater<int>());
    vector<int> cnt;
    cnt.reserve(k);
    unordered_set<int> visited;
    
    for (i = 1; i <= k; ++i) {
        visited.insert(bak[i]);
    }

    int j = 1;
    for (i = 1; i <= n; ++i) {
        if (visited.count(p[i])) {
            j = i;
            break;
        }
    }
    for (i = j + 1; i <= n; ++i) {
        if (visited.count(p[i])) {
            cnt.push_back(i - j);
            j = i;
        }
    }
    ll prod = 1, mv = 0;
    for (auto x : cnt) {
        prod = prod * x;
        // prod = prod % mod;
    }
    for (i = 1; i <= k; ++i) {
        mv += bak[i];
        // mv %= mod;
    }
    printf("%lld %lld\n", mv, prod % mod);
    return 0;
}