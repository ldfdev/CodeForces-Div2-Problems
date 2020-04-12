#include <bits/stdc++.h>

const int max_size = 2 * 1e5 + 2;
char s[max_size];
int dp[max_size];

int main()
{
    int tests, d, i, n, prev;
    char c = 'R';
    s[0] = c;
    scanf("%d", &tests);
    scanf("%c", &c);
    while(tests--) {
        i = 1; d = 0; prev = 0;
        scanf("%c", &c);
        while(c != '\n') {
            s[i++] = c;
            scanf("%c", &c);
        }
        s[i] = 'R';
        for (n = 1; n <= i; ++n) {
            if (s[n] == 'R') {
                d = std::max(d, n - prev);
                prev = n;
            }
        }
        printf("%d\n", d);
    }
    return 0;
}