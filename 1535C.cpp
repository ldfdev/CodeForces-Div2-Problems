#include<bits/stdc++.h>

typedef long long ll;

const ll _MAX_SIZE = 2e5;
ll dp[_MAX_SIZE];
std::string arr;

struct answer {
    ll next;
    bool matches;
    answer (ll next, bool matches) : next(next), matches(matches) {}
};

answer count_question_marks(ll pos, ll n) {
    ll start_pos = pos;
    bool matches = true;
    // std::cout << "At " << start_pos << " " << arr[start_pos] << "\n";
    assert(arr[start_pos] == '?');
    while (arr[start_pos] == '?') {
        start_pos++;
        if (start_pos == n)
            break;
    }
    if ((start_pos == n) ||
        (pos == 0)) {
        matches = true;
        return answer(start_pos, matches);
    }
    ll positions = start_pos - pos;
    if (arr[pos - 1] == arr[start_pos]) {
        matches = false;
        if (positions & 1)
            matches = true;
    }
    else {
        matches = true;
        if (positions & 1)
            matches = false;
    }
    return answer(start_pos, matches);
}

ll solve() {
    ll n;
    char ch, question_mark = '?';
    std::cin >> arr;
    n = arr.size();
    // std::cout << "arr " << arr << " " << arr.size() << "\n";
    std::fill(dp, dp + n, 1);
    ll i = 0, sum = 0, last_dp = 0;
    bool matches = true;
    while (i < n) {
        if (arr[i] == '?') {
            answer ans = count_question_marks(i, n);
            ll next = ans.next;
            matches = ans.matches;
            // std::cout << "matches " << std::boolalpha << matches << "\n";
            for (ll j = i; j < next; j++) {
                if (j > 0)
                    dp[j] += dp[j - 1];
                sum += dp[j];
            }
            last_dp = next - i;
            i = next;
            continue;
        }
        if (i == 0) {
            sum += dp[i];
            i++;
            continue;
        }
        if (arr[i - 1] == '?') {
            if (matches)
                dp[i] += dp[i - 1];
            else
                dp[i] += last_dp;
            sum += dp[i];
            i++;
            continue;
        }
        if (arr[i] != arr[i - 1]) {
            dp[i] += dp[i - 1];
            sum += dp[i];
            i++;
            continue;
        }
        assert(arr[i] == arr[i - 1]);
        sum += dp[i];
        i++;
    }
    return sum;
}


int main() {
    ll tests;
    std::cin >> tests;
    for (ll test = 0; test < tests; test++)
        std::cout << solve() << "\n";
    return 0;
}