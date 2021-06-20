#include <bits/stdc++.h>

// same solution works for 1526C2

typedef long long ll;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
    ll health = 0, n, potion, taken = 0;
    std::cin >> n;
    for (ll i = 0; i < n; i++) {
        std::cin >> potion;
        health += potion;
        taken++;
        if (potion < 0) {
            pq.push(potion);
        }
        while(health < 0) {
            ll bad = pq.top();
            // std::cout << "Top is " << bad << "\n";
            pq.pop();
            health -= bad;
            taken--;
        }
    }
    assert(health >= 0);
    std::cout << taken;
    return 0;
}