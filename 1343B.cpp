#include <bits/stdc++.h>



int main()
{
    int tests;
    scanf("%d", &tests);
    while(tests--) {
        long n;
        scanf("%ld", &n);
        if ((n % 4) != 0) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
            long k = (n / 2);
            for (long i = 1; i < k; i++) {
                printf("%ld ", 2 * i);
            }
            printf("%ld ", 3 * k);
            for (long i = 1; i < k; i++) {
                printf("%ld ", 2 * i + 1);
            }
            printf("%ld\n", 2 * k + 1);
        }
    }
    return 0;
}