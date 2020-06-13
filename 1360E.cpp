#include <stack>
#include <utility>
#include <string>
#include <iostream>

char cannons[50][50];
int n;

inline void bfs(int i, int j) {
    if (cannons[i][j] != '1')
        return;
    std::stack<std::pair<int, int>> unvisited;
    unvisited.push(std::make_pair(i, j));
    while(unvisited.size() > 0) {
        std::pair<int, int> cij = unvisited.top();
        unvisited.pop();
        int ci = cij.first, cj = cij.second;
        cannons[ci][cj] = 'g';
        if (ci > 0)
            if (cannons[ci - 1][cj] == '1')
                unvisited.push(std::make_pair(ci - 1, cj));
        if (cj > 0)
            if (cannons[ci][cj - 1] == '1')
                unvisited.push(std::make_pair(ci, cj - 1));
    }
}

std::string solve() {
    // g for good | b for bad
    std::cin >>n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> cannons[i][j];
    for (int i = 0; i < n; i++)
        if (cannons[i][n - 1] == '1')
            bfs(i, n - 1);
    for (int i = 0; i < n; i++)
        if (cannons[n - 1][i] == '1')
            bfs(n- 1, i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cannons[i][j] == '1')
                return "no";
    return "yes";
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.sync_with_stdio(false);

    int tests;
    std::cin >> tests;
    while(tests--) {
        std::cout << solve() << std::endl;
    }
    return 0;
}