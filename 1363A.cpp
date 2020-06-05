#include <bits/stdc++.h>

int arr[1000];

int main ()
{
    int tests, n, x;
    scanf("%d", &tests);
    while (tests--) {
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%d", arr + i);
        std::string answer = "No";
        int odd = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & 1) {
                ++odd;
            }
        }
        if (odd & 1) {
            answer = std::string("Yes");
            if ((n==odd) && (x % 2 == 0))
                answer = std::string("No");
        }
        else if ((odd > 0) && (x < n)) {
            if (odd != n)
                answer = std::string("Yes");
            else if (x & 1)
                answer = std::string("Yes");
        }
        printf("%s\n", answer.c_str());
    }
    return 0;
}