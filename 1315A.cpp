#include <bits/stdc++.h>

int main()
{
    int tests, a, b, x, y;
    std::cin >> tests;
    while(tests--) {
        std::cin >> a >> b >> x >> y;
        ++x, ++y;
        std::cout << std::max({(x - 1) * b, (a - x) * b, (y - 1) * a, (b - y) * a}) << std::endl;
    }
    return 0;
}