#include <bits/stdc++.h>

struct node
{
    int  sp, p, cost;
    node(): sp(0), p(0), cost(0) {}
};

std::vector<node> spaths;
std::vector<std::vector<int>> adjlist;
struct sp_comp {
    /* sorting crtierion
     * sore by each node's cost
     * where cost is node.sp - node.d
     *   +sp (gain in happiness if node is marked as indistry)
     *   -cost (decrease in happiness due to sp of node's descendands decrease by 1 each)
     */
    bool operator() (const int& a, const int& b) const
    {
        // bigger elements first
        int costa = (spaths[a].sp - spaths[a].cost), costb = (spaths[b].sp - spaths[b].cost);
        if (costa == costb)
            return (a > b);
        return (costa > costb);
    }
};

std::unordered_set<int> visited;
void dfs(int parent) {
    visited.insert(parent);
    for (int node : adjlist[parent]) {
        if (visited.count(node))
            continue;
        spaths[node].sp = 1 + spaths[parent].sp;
        spaths[node].p = parent;
        dfs(node);
    }
    
    for (int node : adjlist[parent]) {
        if (node == spaths[parent].p)
            continue;
        spaths[parent].cost += 1 + spaths[node].cost;
    }
}

int main()
{
    int a, b, i, cities, industries;
    scanf("%d%d", &cities, &industries);
    spaths = std::vector<node>(1 + cities);
    adjlist = std::vector<std::vector<int>>(cities + 1, std::vector<int>());
    for (i = 1; i < cities; i++) {
        scanf("%d%d", &a, &b);
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(1);
    std::multiset<int, sp_comp> biggest_first;
    for(i = 1; i <= cities; i++) {
        biggest_first.insert(i);
    }
    long long happiness = 0;
    for (i = 1; i <= industries; i++) {
        auto it = biggest_first.begin();
        int x = *it;
        biggest_first.erase(it);
        happiness += (spaths[x].sp - spaths[x].cost);
    }
    printf("%lld\n", happiness);
    return 0;
}