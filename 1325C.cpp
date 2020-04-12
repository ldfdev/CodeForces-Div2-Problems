#include <bits/stdc++.h>

int main()
{
    int i, nodes, in, ou;
    scanf("%d", &nodes);
    std::vector<int> degree(nodes + 1, 0), labels(nodes, -1);
    int leaf_label = 0;
    std::vector<std::pair<int, int>> edges;
    edges.reserve(nodes);
    for(i = 1; i < nodes; ++i) {
        scanf("%d %d", &in, &ou);
        ++degree[in], ++degree[ou];
        edges.push_back(std::make_pair(in, ou));
    }
    for(i = 0; i + 1 < nodes; ++i) {
        if (degree[edges[i].first] == 1) {
            labels[i] = leaf_label++;
        }
        else if (degree[edges[i].second] == 1) {
            labels[i] = leaf_label++;
        }
    }
    for (i = 0; i < nodes - 1; ++i) {
        if (labels[i] == -1)
            labels[i] = leaf_label++;
        printf("%d\n", labels[i]);
    }

    return 0;
}