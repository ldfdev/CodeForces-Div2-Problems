#include <bits/stdc++.h>

typedef unsigned long long ull;

ull count_haha(const std::string& ref) {
    ull haha_occurences = 0;
    for (ull index = 0; index < ref.size(); index++) {
        if ("haha" == ref.substr(index, 4)) {
            ++haha_occurences;
        }
    }
    return haha_occurences;
}

struct STRing {
    ull haha_count = 0;
    std::string pref = std::string(), suf = std::string();
    bool is_a_long_string() const {
        return ((pref.size() > 0) && (suf.size() > 0));
    }
};

STRing operator + (const STRing& s1, const STRing& s2) {
    STRing s;
    s.haha_count = s1.haha_count + s2.haha_count;
    s.pref = s1.pref;
    s.suf = s2.suf;
    if (s1.is_a_long_string() && s2.is_a_long_string()) {
        std::string s_ = s1.suf + s2.pref;
        s.haha_count += count_haha(s_);
        return s;
    }
    if (s1.is_a_long_string()) {
        std::string s_ = s1.suf + s2.suf;
        s.haha_count += count_haha(s_);
        s.suf = s_.substr(s_.size() - 3, 3);
        return s;
    }
    if (s2.is_a_long_string()) {
        std::string s_ = s1.suf + s2.pref;
        s.haha_count += count_haha(s_);
        s.pref = s_.substr(0, 3);
        return s;
    }
    std::string s_ = s1.suf + s2.suf;
    if (s_.size() < 6) {
        s.suf = s_;
        return s;
    }
    s.haha_count += count_haha(s_);
    s.pref = s_.substr(0, 3);
    s.suf = s_.substr(s_.size() - 3, 3);
    return s;
}

std::unordered_map<std::string, STRing> cache;

ull solve() {
    cache.clear();
    std::vector<std::string> tokens;
    int statements;
    std::cin >> statements;
    std::string last_assignment;
    while(statements--) {
        tokens.clear();
        std::string token;
        int token_size = 3;

        while(token_size--) {
            std::cin >> token;
            tokens.emplace_back(token);
            if ("=" == token)
                token_size += 2;
        }

        if (tokens.size() == 3) {
            // x := s
            STRing s;
            s.suf = tokens[2];
            // s.haha_count = count_haha(tokens[2]);
            cache[tokens[0]] = s;
        } else {
            // x = a + b
            assert(tokens.size() == 5);
            cache[tokens[0]] = cache.at(tokens[2]) + cache.at(tokens[4]);
        }
        last_assignment = tokens[0];
    }
    if(!cache[last_assignment].is_a_long_string())
        cache[last_assignment].haha_count = count_haha(cache[last_assignment].suf);
    return cache[last_assignment].haha_count;
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int tests;
    std::cin >> tests;
    while(tests--) {
        std::cout << solve() <<  "\n";
    }
    return 0;
}