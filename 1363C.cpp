#include <bits/stdc++.h>

typedef long long ll;
ll n, x;
std::vector<std::vector<ll>> adjList(1001);

std::string solve() {
    std::cin >> n >> x;
    if (n == 1)
        return "Ayush";
    ll i, j, k;
    for (i = 1; i <= n; i++)
        adjList[i].clear();
    for (i = 1; i < n; i++) {
        std::cin >> j >> k;
        adjList[j].push_back(k);
        adjList[k].push_back(j);
    }
    if (adjList[x].size() == 1)
        return "Ayush";
    if ( n & 1)
        return "Ashish";
    return "Ayush";
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.sync_with_stdio(false);
    ll tests;
    std::cin >> tests;
    while(tests--) {
        std::cout << solve() << "\n";
    }
    return 0;
}