#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <utility>


using namespace std;

int main()
{
    int n, m, u, v, node_parents;
    string verdict = "YES";
    cin >> n >> m;
    vector<list<int>> nodes(n + 1);
    vector<int> colors(n + 1, -1); // colors 0, 1 and for unassigned -1
    vector<pair<int,int>> order_of_edges;
    for (auto i = 1; i <= m; i++) {
        cin >> u >> v;
        nodes[u].push_front(v);
        nodes[v].push_front(u);
        order_of_edges.push_back(make_pair(u, v));
    }

    // dfs the tree
    list<int> stack;
    stack.push_front(1);
    colors[1] = 0; //arbitrarily chosen, could have been 1
    vector<bool> visited(n+1,false);
    while(!stack.empty()) {
        int node_current = stack.front();
        stack.pop_front();
        visited[node_current] = true;

        // cout << "current node: " << node_current << endl << "    ";
        // for (auto& child : nodes[node_current]) {
        //     cout << child << "[c" << colors[child] << "];  ";
        // }
        // cout << endl;
        
        int child_color = (colors[node_current] == 1) ? (0) : (1);
        for (auto& child : nodes[node_current]) {
            if(visited[child] == false) {
                stack.push_front(child);
                if ((colors[child] == -1) || (colors[child] == child_color)) {
                    colors[child] = child_color;
                }
                else {
                    verdict = "NO";
                    stack = list<int>(); // necessary to exit while loop
                    break;
                }
            }
        }
    }
    
    cout << verdict << endl;
    if (verdict == "YES") {
        for(auto& p : order_of_edges) {
            int edgeNode1 {p.first}, edgeNode2 {p.second};
            if ((colors[edgeNode1] == 1) && (colors[edgeNode2] == 0))
                cout << "1";
            else if ((colors[edgeNode1] == 0) && (colors[edgeNode2] == 1))
                cout << "0";
        }
    }
    cout << endl;
    return 0;
}