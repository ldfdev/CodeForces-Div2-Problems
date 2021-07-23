#include <bits/stdc++.h>

const int n_max = 1e5 + 1;
int good_coprimes[n_max];
int gc_size = 1;

int gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(a % b, b);
}


bool already_satisfies (unsigned long long n) {
    unsigned long long p = 1;
    for (int index = 1; index <= gc_size; index++) {
        p *= good_coprimes[index];
        p %= n;
    }
    return (p == 1ull);
}

void good_divisors(int n) {
    int index = 2;
    for (int p = 2; p < n - 1; p++) {
        if (gcd(n, p) != 1)
            continue;
        good_coprimes[index++] = p;
    }
    gc_size = index - 1;
}

void solve() {
    int n;
    std::cin >> n;
    good_divisors(n);
    if (!already_satisfies((unsigned long long)n))
        good_coprimes[++gc_size] = n - 1;
}

int main()
{
    good_coprimes[1] = 1;
    solve();
    std::cout << gc_size << "\n";
    for (int i = 1; i <= gc_size; i++)
        std::cout << good_coprimes[i] << " ";
    std::cout << "\n";
    return 0;
}