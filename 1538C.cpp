#include <bits/stdc++.h>

const int sizemax = 2 + 2e5;
typedef long long ll;
ll arr[sizemax];

ll solve() {
    ll n, l, r, pairs = 0;
    std::cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];
    std::sort(arr, arr + n);

    // std::cout << "arr: ";
    // for (int i = 0; i < n; i++)
    //     std::cout << arr[i] << " ";
    // std::cout << "\n";

    for(int i = 0; i < n; i++) {
        ll *lower_b, *upper_b;
        // lower_b is smallest num for which arr[i] + lower_b >= l
        lower_b = std::lower_bound(arr + i + 1, arr + n, l - arr[i], std::less<ll>());
        if (lower_b == arr + n)
            continue;
        // upper_b is biggest  num for which arr[i] + upper_b <= r
        upper_b = std::lower_bound(arr + i + 1, arr + n, r - arr[i] + 1, std::less<ll>());
        upper_b -= 1; // std::upper_bound gives the first elem GT than value
                      //  so the element before GT must be Less than or equal
        if (arr[i] + *lower_b < l)
            continue;
        if (upper_b < arr + i + 1)
            continue;
        // std::cout << "index " << i << " " << arr[i]
        //     << ">= " << l - arr[i]
        //     << "<= " << r - arr[i] << "\n";
        // std::cout << "lower " << *lower_b << "\n";
        // std::cout << "upper " << *upper_b << "\n";
        pairs += upper_b - lower_b + 1;
    }
    return pairs;
}

int main()
{
    // fast input
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int tests;
    std::cin >> tests;
    for(int i = 0; i < tests; i++) {
        std::cout << solve() << "\n";
    }
}