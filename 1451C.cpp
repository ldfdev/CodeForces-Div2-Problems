#include <bits/stdc++.h>


std::string solve() {
    long long n, k;
    std::cin >> n >> k;
    std::string a, b;
    std::cin >> a >> b;
    long long freqa[26], freqb[26];
    std::fill(freqa, freqa + 26, 0ll);
    std::fill(freqb, freqb + 26, 0ll);
    for(const char& ch : a) {
        freqa[ch - 'a'] += 1;
    }
    for(const char& ch : b) {
        freqb[ch - 'a'] += 1;
    }
    long long reserve = 0;
    for (int i = 0; i < 26; i++) {
        reserve += std::max(0LL, freqa[i] - freqb[i]) / k;
        if (freqa[i] >= freqb[i]) {
            continue;
        }
        long long need = freqb[i] - freqa[i];
        need /= k;
        if (freqb[i] > k * need + freqa[i]) {
            ++need;
        }
        assert(freqb[i] <= k * need + freqa[i]);
        if (need > reserve) {
            return "no";
        }
        reserve -= need;
    }
    if (reserve > 0) {
        return "no";
    }
    return "yes";
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    long long tests {};
    std::cin >> tests;
    while(tests --) {
        std::cout << solve() << "\n";
    }
    return 0;
}