#include <bits/stdc++.h>

int main()
{
    int tests;
    std::cin >> tests;
    while(tests --)
    {
        int n, x, a, b;
        std::cin >> n >> x >> a >> b;
        if (a > b)
            std::swap(a, b);
        std::cout << std::min(b - a + x, n - 1) << std::endl;
    }
    return 0;
}