#include <vector>
#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

int main()
{
    ll n, k, A, minimum_cost = 0;
    cin >> n >> k;
    vector<ll> lift(n), cost(n);
    for (int i = 0; i < n; ++i)
        cin >> lift[i];
    cin >> A;
    for (int i = 0; i < n; ++i)
        cin >> cost[i];
    for (int i = 0; i < n; ++i) {
        if ( k + (i + 1) * A < lift[i]) {
            cout << "-1\n";
            return 0;
        }
    }
    multiset<ll> smallest_cost;
    for (int i = 0; i < n; ++i) {
        smallest_cost.insert(cost[i]);
        if ( k < lift[i]) {
            int times = 0;
            for (int j = 0; j < i; ++j) {
                k += A; ++times;
                if (k >= lift[i])
                    break;
            }
            for (int tt = 0; tt < times; ++tt) {
                ll current_cost = *smallest_cost.begin();
                smallest_cost.erase(current_cost);
                minimum_cost += current_cost;
            }
        }
    }
    cout << minimum_cost << endl;
    return 0;
}
