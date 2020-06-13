#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.sync_with_stdio(false);

    ll n;
    std::cin >> n;
    std::vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        std::cin >> arr[i];
    ll best_solution = 0, temp_solution;
    if (n > 2) {
        for (ll i = 0; i < n - 2; i++) {
            for (ll j = i + 1; j < n - 1; j++) {
                for (ll k = j + 1; k < n; k++) {
                    temp_solution = arr[i] | arr[j] | arr[k];
                    best_solution = std::max(temp_solution, best_solution);
                }
            }
        }
    } else if (n > 1) {
        best_solution = arr[0] | arr[1];
    } else {
        best_solution = arr[0];
    }
    std::cout << best_solution << "\n";
    return 0;
}