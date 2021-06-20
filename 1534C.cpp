#include <bits/stdc++.h>
typedef unsigned long long ull;

ull modulo = 7 + 1e9;
ull const sizemax = 4e5;
ull first_row[sizemax], second_row[sizemax];
ull perm[sizemax + 1];
bool visited[sizemax + 1];

ull fast_exp(ull base, ull power) {
    if (power == 0)
        return 1;
    ull result = fast_exp((base * base) % modulo, power / 2);
    if (power & 1)
        return (result * base) % modulo;
    return result % modulo;
}

ull solve() {
    ull n ;
    std::cin >> n;
    for (ull i = 0; i < n; i++)
        std::cin >> first_row[i];
    for (ull i = 0; i < n; i++)
        std::cin >> second_row[i];
    for (ull i = 0; i < n; i++)
        perm[first_row[i]] = second_row[i];
    std::fill(visited, visited + 1 + n, false);
    ull cycles = 0;
    for (ull i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        ull start = perm[i];
        while(i != start) {
            visited[start] = true;
            start = perm[start];
        }
        cycles += 1;
    }
    return fast_exp(2, cycles);
}


int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    
    int tests;
    std::cin >> tests;
    while(tests--) {
        std::cout << solve() << "\n";
    }
    return 0;
}