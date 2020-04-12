#include <bits/stdc++.h>

int gcd(int a, int b) {
    if (a == b)
        return a;
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(a - b, b);
}

int main()
{
    int tests, n, m, i, j;
    scanf("%d", &tests);
    int color[1000 + 1], elements[1001];
    while(tests--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", elements + i);
        }
        std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        std::map<int, int> decode;
        m = 0;
        for (i = 1; i <= n; i++)
            for (int prm : primes)
                if (elements[i] % prm == 0) {
                    if (!decode.count(prm))
                        decode[prm] = ++m;
                    color[i] = decode[prm];
                    break;
                }
        printf("%d\n", m);
        for (i = 1; i <= n; i++)
            printf("%d ", color[i]);
        printf("\n");
    }
    return 0;
}