#include <bits/stdc++.h>

struct ratio {
    int d, k;
};

int gcd(int a, int b) {
    if (a > b)
        return gcd(b, a);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

std::string compute_ratio(int d_count, int k_count) {
    struct ratio r;
    int gcd_ = gcd(d_count, k_count);
    r.d = d_count / gcd_;
    r.k = k_count / gcd_;
    std::stringstream ss;
    ss << r.d
       << "_"
       << r.k;
    // std::cout << "Ratio of " << d_count << "/" << k_count << " is " << ss.str() << "\n";
    return ss.str();
}

const int max_size = 1 + 5e5;
std::vector<int> primes;
char plank[max_size];
int  dp[max_size];
char d = 'D', k = 'K';

void solve() {
    int n, d_count = 0, k_count = 0;
    // where ratio k is first encountered
    std::unordered_map<std::string, int> cache;
    char ch;
    std::cin >> n;
    // std::cin >> ch;
    for (int i = 0; i < n; i++)
        std::cin >> plank[i];
    for (int i = 0; i < n; i++) {
        // std::cout << "plank [" << i << "] = " << plank[i] << "\n";
        if (plank[i] == d)
            d_count++;
        if (plank[i] == k)
            k_count++;
        // std::cout << counter.d << " " << counter.k << "\n";
        dp[i] = 1;
        std::string current_ratio = compute_ratio(d_count, k_count);
        // std::cout << "Current ratio " << current_ratio << ": ";
        // for (auto it : cache)
        //     std::cout << it.first << " ";
        // std::cout << "\n";
        auto pos_iterator = cache.find(current_ratio);
        if (cache.end() != pos_iterator)
            // pos_iterator->second + 1 is the length of the first prefix with ration current_ratio
            ++cache[current_ratio]; 
        else
            cache[current_ratio] = 1;
        dp[i] = cache[current_ratio];
    }

    for (int i = 0; i < n; i++)
        std::cout << dp[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int tests;
    std::cin >> tests;
    for(int test = 0; test < tests; test++) {
        solve();
    }
    return 0;
}