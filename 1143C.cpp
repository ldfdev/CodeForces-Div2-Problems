#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int n, node_parents, root;
    cin >> n;
    vector<int> node_respect_parents(n + 1);
    vector<int> parent(n+1);
    vector<list<int>> nodes(n + 1);
    for (auto i = 1; i <= n ; i++) {
        cin >> node_parents;
        parent[i] = node_parents;
        if (node_parents == -1)
            root = i;
        else
            nodes[node_parents].push_back(i);
        cin >> node_respect_parents[i];
    }
    vector<int> node_should_be_removed = node_respect_parents;

    // dfs the tree
    list<int> stack;
    stack.push_front(root);
    vector<int> visited (n+1, 0);
    while(!stack.empty()) {
        int node_current = stack.front();
        visited[node_current] = 1;
        // cout << "current node [" << node_current << "] has parent node [" << parent[node_current] << "]\n";
        stack.pop_front();
        if (node_respect_parents[node_current] == 0) // node respects parent
            {
                if (parent[node_current] != -1)
                    node_should_be_removed[parent[node_current]] = 0;
            }
        for (auto& child : nodes[node_current])
            if (visited[child] == 0) {
                stack.push_front(child);
                // break;
            }
    }
    int deleted_nodes_exist = 0;
    for (int i = 1; i <= n; i++)
        if (node_should_be_removed[i] == 1) {
            cout << i << " ";
            deleted_nodes_exist = 1;
        }
    if (deleted_nodes_exist == 0)
        cout << "-1";
    cout << endl;
    // vector<int> node_is_respected_by_children(n+1, 0);
    // for (int i = 1; i <= n; i++) {
    //     for (auto child : nodes[i])
    //         if (node_respect_parents[child] == 1) {
    //             node_is_respected_by_children[i] = 1;
    //             break;
    //         }
    // }


    return 0;
}