#include <bits/stdc++.h>

typedef unsigned long long ll;

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int tests;
    std::cin >> tests;
    while(tests--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        int counter = 0;
        if (n == 1) {
            std::cout << "Yes\n";
        }
        else {
            while(counter < n - 1) {
                if (abs(a[1 + counter] - a[counter]) < 2)
                    ++counter;
                else
                    break;
            }
            if (counter == n - 1)
                std::cout << "Yes\n";
            else
                std::cout << "No\n";
        }
    }

    return 0;
}