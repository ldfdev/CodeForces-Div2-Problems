#include <bits/stdc++.h>

typedef long long ll;

const size_t max_primes_size = 1e5;
int nums[max_primes_size];
std::vector<int> primes;

void precompute_primes() {
    int marked = -1;
    for (size_t i = 3; i < max_primes_size; i += 2) {
        if (marked == nums[i])
            continue;
        primes.push_back(i);
        // must be unsigned j not to have integer overflow
        for (size_t j = i * i; j < max_primes_size; j += i)
            nums[j] = marked;
    }
}

ll prime_exponents(ll num) {
    ll exponents = 0;
    while((num & 1) == 0) {
        ++exponents;
        num >>= 1;
    }
    for (ll p : primes) {
        while (num % p == 0) {
            exponents += 1;
            num = num / p;
        }
        if (p > num)
            break;
    }
    // most likely num is prime
    if (num != 1)
        exponents++;
    return exponents;
}

std::string solve() {
    ll a, b, k;
    std::cin >> a >> b >> k;
    if (b < a)
        std::swap(a, b);
    ll minimum = 0, maximum;
    // deviding by 1 is forbidden in this problem
    if ((a > 1) && (b > 1))
        minimum = 2;
    if (b % a == 0)
        minimum = 1;
    if (a == b)
        minimum = 0;
    maximum = prime_exponents(a) + prime_exponents(b);
    //  step 1: a = a / a -> 1
    // step 2: b = b / b -> 1
    if ((k == 1) && (a == b))
        return "no";
    if ((k >= minimum) && (k <= maximum))
        return "yes";
    return "no";
}

int main()
{
    // fast input
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    precompute_primes();
    int tests;
    std::cin >> tests;
    while(tests--) {
        std::cout << solve() << "\n";
    }
    return 0;
}
