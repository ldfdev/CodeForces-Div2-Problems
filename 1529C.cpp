#include <bits/stdc++.h>
/// Parsa Humongous Tree

typedef long long ull;

struct Vertex{
    ull l, r;
};

const ull N_MAX = 2 + 2e5;

ull traversal[N_MAX], rem[N_MAX], dp[2][N_MAX];
std::unordered_map<ull, std::unordered_set<ull>> adj;
Vertex vertices[N_MAX];

void print_adj() {
    std::cout << "Adjacency list\n";
    for (auto key = adj.begin(); key != adj.end(); ++ key) {
        std::cout << "key " << key->first << ": {";
        for (auto& v: key->second) {
            std::cout << v << ", ";
        }
        std::cout << "}\n";
    }
}

void print_dp(ull n) {
    std::cout << "dp\n";
    for (ull i = 1; i <= n; i++) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    ull items[2] = {0, 1};
    for (ull index : items) {
        for (ull i = 1; i <= n; i++) {
            std::cout << dp[index][i] << "  ";
        }
        std::cout << "\n";
    }
}

ull bfs(ull source) {
    std::unordered_set<ull> visited;
    ull beg {0}, end {1};
    traversal[beg] = source;
    while (beg < end) {
        ull s = traversal[beg];
        visited.insert(s);
        ull rem_index = 0;
        for (ull node : adj[s]) {
            if (visited.find(node) != visited.end()) {
                rem[rem_index++] = node;
                continue;
            }
            // ignore leaf nodes
            if (adj[node].size() == 1 &&
                visited.find(*adj[node].begin()) != visited.end())
                continue;
            traversal[end++] = node;
        }
        for (ull i = 0; i < rem_index; i++) {
            adj[s].erase(rem[i]);
        }
                
        beg += 1;
    }
    return end;
}

ull solve() {
    ull n;
    std::cin >> n;
    for (ull i = 1; i <= n; i++) {
        ull l, r;
        std::cin >> l >> r;
        vertices[i].l = l;
        vertices[i].r = r;
    }
    adj.clear();
    for (ull i = 1; i < n; i++) {
        ull u, v;
        std::cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    ull source = 1; // pick 1 node as starting point
    ull traversal_end_index = bfs(source);

    std::fill(dp[0], dp[0] + n + 1, 0);
    std::fill(dp[1], dp[1] + n + 1, 0);

    // for (ull node = traversal_end_index - 1; node > -1; node--) {
    //     std::cout << traversal[node] << " ";
    // }
    // std::cout << std::endl;
    // print_adj();
    for (ull index = traversal_end_index - 1; index > -1; index--) {
        ull i = traversal[index];
        // std::cout << "Node " << i << " Children size " << adj[i].size() << "\n    ";
        // for (auto ch : adj[i])
        //     std::cout << ch << " "; std::cout << "\n";
        for (auto ch = adj[i].begin(); ch != adj[i].end(); ch++) {
            ull j = *ch;
            dp[0][i] += std::max(dp[0][j] + abs(vertices[i].l - vertices[j].l),
                            dp[1][j] + abs(vertices[i].l - vertices[j].r));
            dp[1][i] += std::max(dp[0][j] + abs(vertices[i].r - vertices[j].l),
                            dp[1][j] + abs(vertices[i].r - vertices[j].r));
        }
    }
    // print_dp(n);
    return std::max(dp[0][source], dp[1][source]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; test++) {
        std::cout << solve() << std::endl;
    }
}