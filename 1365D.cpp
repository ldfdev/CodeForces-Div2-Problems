#include <bits/stdc++.h>

int n, m;
char maze[50][50];
int fill[50][50];

void reset_fill() {
    for (int r = 0; r < n;r++)
    for (int c = 0; c < m; c++)
        fill[r][c] = 0;
}

enum class person {good, bad};

bool are_all_good_cells_reachable(int good_cells_num) {
    std::vector<std::pair<int, int>> stac;
    stac.reserve(n * m);
    int head = 0, good_cells = 0;
    stac.push_back({n - 1, m - 1});
    while(head < stac.size()) {
        std::pair<int, int> current_cel = stac[head++];
        // std::cout << "   Inspecting cell " << current_cel.first << "," << current_cel.second << " = " << maze[current_cel.first][current_cel.second] << "\n";
        if (fill[current_cel.first][current_cel.second] > 0)
            continue;
        if (maze[current_cel.first][current_cel.second] == '#')
            continue;
        if (maze[current_cel.first][current_cel.second] == 'B')
            return false;
        if (maze[current_cel.first][current_cel.second] == 'G')
            ++good_cells;
        
        fill[current_cel.first][current_cel.second] = 1;

        if (current_cel.first > 0)
            stac.push_back({current_cel.first - 1, current_cel.second});
        if (current_cel.first < n - 1)
            stac.push_back({current_cel.first + 1, current_cel.second});
        if (current_cel.second > 0)
            stac.push_back({current_cel.first, current_cel.second - 1});
        if (current_cel.second < m - 1)
            stac.push_back({current_cel.first, current_cel.second + 1});
        
    }
    // std::cout << "Found " << good_cells << " good cells out of " << good_cells_num << "\n";
    return (good_cells_num == good_cells);
}

void block_neighboring_cells(){
    std::vector<std::pair<int, int>> stac;
    stac.reserve(n * m);
    int head = 0;
    stac.push_back({n - 1, m - 1});
    while(head < stac.size()) {
        std::pair<int, int> current_cel = stac[head++];
        if (fill[current_cel.first][current_cel.second] > 0)
            continue;
        if (maze[current_cel.first][current_cel.second] == '#')
            continue;
        
        fill[current_cel.first][current_cel.second] = 1;

        if (current_cel.first > 0) {
            if ('B' == maze[current_cel.first - 1][current_cel.second])
                maze[current_cel.first][current_cel.second] = '#';
            else
                stac.push_back({current_cel.first - 1, current_cel.second});
        }
        if (current_cel.first < n - 1){
            if ('B' == maze[current_cel.first + 1][current_cel.second])
                maze[current_cel.first][current_cel.second] = '#';
            else
                stac.push_back({current_cel.first + 1, current_cel.second});
        }
        if (current_cel.second > 0){
            if ('B' == maze[current_cel.first][current_cel.second - 1])
                maze[current_cel.first][current_cel.second] = '#';
            else
                stac.push_back({current_cel.first, current_cel.second - 1});
        }
        if (current_cel.second < m - 1){
            if ('B' == maze[current_cel.first][current_cel.second + 1])
                maze[current_cel.first][current_cel.second] = '#';
            else
                stac.push_back({current_cel.first, current_cel.second + 1});
        }
    }
}

void print_maze() {
    for (int row = 0; row < n; row++){
        for (int col = 0; col < m; col++)
            std::cout << maze[row][col];
        std::cout << "\n";
    }
}

std::string solve() {
    int good_persons = 0;
    std::cin >> n >> m;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++) {
            std::cin >> maze[r][c];
            if (maze[r][c] == 'G')
                ++good_persons;
        }
    reset_fill();
    // print_maze();
    block_neighboring_cells();
    reset_fill();
    // print_maze();
    if (are_all_good_cells_reachable(good_persons))
        return "yes";
    return "no";
}

int main()

{
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.sync_with_stdio(false);

    int tests;
    std::cin >> tests;
    while(tests--) {
        std::cout << solve() << "\n";
    }
    return 0;
}