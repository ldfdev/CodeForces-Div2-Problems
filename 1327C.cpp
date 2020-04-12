#include <bits/stdc++.h>

typedef long long ll;
struct chip {
    int sx, sy;
};

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    std::vector<chip> c(k + 1), atteint(k + 1);
    for (int i = 1; i <= k; ++i) {
        scanf("%d %d", &c[i].sx, &c[i].sy);
    }
    for (int i = 1; i <= k; ++i) {
        scanf("%d %d", &atteint[i].sx, &atteint[i].sy);
    }
    ll ops = n - 1 + m - 1 + n * (m - 1) + n - 1;
    printf("%lld\n", ops);
    //move all chips to first column
    for (int i = 1; i < m; ++i) {
        printf("L");
    }
    //move all chips to first row
    for (int i = 1; i < n; ++i) {
        printf("U");
    }
    // visits all cells untill reach pos (n, m)
    for (int row = 1; row <= n; ++row) {
        char chr = 'L';
        if (row & 1)
            chr = 'R';
        for(int i = 1; i < m; ++i)
            printf("%c", chr);
        if (row < n)
            printf("D");
    }
    printf("\n");
    return 0;
}