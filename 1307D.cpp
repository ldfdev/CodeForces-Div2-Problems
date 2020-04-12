#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;

ll inf = 1e9;

struct Graph {
    Graph(ll vertices, ll edges) : V(vertices), E(edges) {}
    void initialize() {
        adj_list = vector<vector<ll>>(1 + V, vector<ll>());
        ll in, out;
        for (ll i = 1; i <= E; ++i) {
            cin >> in >> out;
            adj_list[in].push_back(out);
            adj_list[out].push_back(in);
        }
    }

    vector<ll> precompute_bfs(ll start) {
        vector<ll> dis(1 + V, inf);
        dis[start] = 0;
        vector<ll> queue;
        ll tail = 0;
        queue.push_back(start);
        while(tail < queue.size()) {
            ll v = queue[tail++];
            for (ll neighbor : adj_list[v])
                if(dis[neighbor] == inf) {
                    queue.push_back(neighbor);
                    dis[neighbor] = 1 + dis[v];
                }
        }
        return dis;
    }
    vector<vector<ll>> adj_list;
    ll V, E;
};

int main()
{
    ll V, E, K;
    cin >> V >> E >> K;
    vector<ll> specials(K);
    for(auto i = 0; i < K; ++i)
        cin >> specials[i];
    Graph g(V, E);
    g.initialize();
    
    vector<ll> distances_from_1, distances_to_v;
    distances_from_1 = g.precompute_bfs(1);
    distances_to_v = g.precompute_bfs(V);
    
    vector<pair<ll, ll>> distances_as_pairs;
    for (ll s : specials) {
        distances_as_pairs.push_back(make_pair(distances_from_1[s] - distances_to_v[s], s));
    }
    
    sort(distances_as_pairs.begin(), distances_as_pairs.end());
    ll longest_new_road = 0;
    ll longest_distance = -inf;
    for (auto x : distances_as_pairs) {
        longest_new_road = max(longest_new_road, longest_distance + distances_to_v[x.second]);
        longest_distance = max(longest_distance, distances_from_1[x.second]);
    }
    //// shortest path [1 .. V] without special roads or shortest path with speacial roads
    cout << min(longest_new_road + 1, distances_from_1[V]) << endl;

    return 0;
}