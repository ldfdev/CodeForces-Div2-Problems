#include <bits/stdc++.h>

#define long long int;

int main()
{
    int tests;
    std::cin >> tests;
    while(tests--) {
        int n, k;
        std::cin >> n >> k;
        if (k >= n)
            std::cout << 1 << std:: endl;
        else {
            int biggest_divisor = 1; // buy k packages x1 shovel each
            for (int i = 2; i <= sqrt(n); i++) {
                if (i > k)
                    break;
                if (n % i != 0)
                    continue;
                biggest_divisor = i;
                if ((n / i) <= k) {
                    biggest_divisor = std::max(biggest_divisor, (n / i));
                    break;
                }
            }
            std::cout << (n / biggest_divisor) << std::endl;
        }
    }
}