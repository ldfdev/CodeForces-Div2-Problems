#include <bits/stdc++.h>

int main()
{
    int tests;
    std::cin >> tests;
    while(tests --)
    {
        int x, y, last, next;
        std::string ans = "NO";
        std::cin >> x >> y;
        last = x;
        if (x >= y)
            ans = "YES";
        else {
            if (last % 2 == 0)
                next = last / 2 * 3;
            else
                next = (last - 1) / 2 * 3;
            if (last < next)
                ans = "YES";
            if ((last == 2) && (y > 3))
                ans = "NO";
        }
        std::cout << ans << std::endl;
    }
    return 0;
}