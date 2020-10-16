#include <bits/stdc++.h>

typedef long long ll;

struct data {
    ll time;
    ll alice;
    ll bob;
};

struct comp {
    bool operator()(const data& d1, const data& d2) {
        if (d1.time == d2.time)
            return ((d1.alice == d2.alice) && (d1.bob == d2.bob));
        return (d1.time < d2.time);
    }
};

int main()
{
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.sync_with_stdio(false);

    ll n, k;
    std::cin >> n >> k;
    std::vector<data> items(n);
    for (ll i = 0; i < n; i++) {
        std::cin >> items[i].time
                 >> items[i].alice
                 >> items[i].bob;
    }
    std::sort(items.begin(), items.end(), comp());

    ll required_time = 0, required_alice = 0, required_bob = 0;
    for (ll i = 0; i < n; i++) {
        std::cout << items[i].time << " " << items[i].alice << " " << items[i].bob << "\n";
        if ((required_alice >= k) && (required_bob >= k))
            break;
        bool condition = false;
        if ((items[i].alice == 1) && (required_alice < k)) {
            condition = true;
            ++required_alice;
        }
        if ((items[i].bob == 1) && (required_bob < k)) {
            condition = true;
            ++required_bob;
        }
        if (condition)
            required_time += items[i].time;
    }
    if ((required_alice < k) || (required_bob < k))
        std::cout << "-1\n";
    else
        std::cout << required_time << std::endl;
    return 0;
}