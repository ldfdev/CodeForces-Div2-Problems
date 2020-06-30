#include <bits/stdc++.h>

typedef long long ll;

ll V, E;
std::vector<std::vector<ll>> adjList;
std::vector<ll> independent_set;

void read_graph() {
    std::cin >> V >> E;
    adjList.resize(V + 1);
    independent_set.resize(V + 1);
    ll a, b;
    for (ll i = 1; i <= E; i++) {
        std::cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
}

ll compute_independent_set(ll startV) {
    std::unordered_set<ll> visited;
    visited.insert(startV);
    
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    read_graph();

    ll independent_set_size = 0;
    std::vector<ll> IS (1 + V);

    for ( ll startV = 1; startV <= V; startV++) {
        ll size = compute_independent_set(startV);
        std::cout << "Frm vertex " << startV << " IS = " << size << "\n    ";
        if (size > independent_set_size) {
            independent_set_size = size;
            IS = independent_set;
        }
        for (ll i = 1; i <= V; i++)
            if (1== independent_set[i])
                std::cout << i << " ";
        std::cout << "\n";
    }
    return 0;
}