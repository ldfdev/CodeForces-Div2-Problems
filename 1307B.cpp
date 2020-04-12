#include <iostream>

using namespace std;

int main()
{
    int tests;
    cin >> tests;
    while(tests--) {
        int n, dist;
        cin >> n >> dist;
        int fav[1 + n];
        for(int i = 1; i <= n; ++i)
            cin >> fav[i];
        int hops_needed = 0;

        int max_hop = fav[1];
        for(int i = 1; i <= n; ++i) {
            if (max_hop < fav[i])
                max_hop = fav[i];
            if (fav[i] == dist) {
                max_hop = dist;
                break;
            }
        }
        if (max_hop == dist)
            hops_needed = 1;
        else if (max_hop > dist)
            hops_needed = 2;
        else if (2 * max_hop >= dist)
            hops_needed = 2;
        else {
            int cnt = dist / max_hop;
            hops_needed = cnt;
            if (dist > cnt * max_hop)
                ++hops_needed;
        }
        cout << hops_needed << endl;
    }
    return 0;
}