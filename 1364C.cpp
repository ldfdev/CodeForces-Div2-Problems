#include <bits/stdc++.h>

typedef unsigned long long ll;

inline ll change_value(ll value, const std::unordered_set<ll>& st) {
    while(st.count(value))
        ++value;
    return value;
}

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.sync_with_stdio(false);

    ll n;
    std::cin >> n;
    std::vector<ll> arr(n), b(n, -1);
    for (ll i = 0; i < n; i++)
        std::cin >> arr[i];
    for (ll i = 0; i < n - 1; i++)
        if (arr[i + 1] != arr[i])
            b[i + 1] = arr[i];
    std::unordered_set<ll> bad_elements;
    for (ll i = 0; i < n; i++)
        bad_elements.insert(arr[i]);
    ll value = change_value(0, bad_elements);
    for (ll i = 0; i < n; i++)
        if (b[i] == -1) {
            b[i] = value;
            value = change_value(value + 1, bad_elements);
        }
    for (ll i = 0; i < n; i++)
        std::cout << b[i] << " ";
        std::cout << "\n";
    return 0;
}