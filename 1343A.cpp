#include <bits/stdc++.h>
long solve(long n) {
    for (int k = 2; k <= n; k++) {
        long t = (1 << k) - 1;
        if ((n % t) == 0)
            return n / t;
    }
    return 0;
}
int main()
{
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        long n;
        scanf("%ld", &n);
        printf("%ld\n", solve(n));
    }
    return 0;
}