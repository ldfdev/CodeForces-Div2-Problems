#include <bits/stdc++.h>

int columns[101];

int main()
{
    int tests, n, i;
    bool verdict;
    scanf("%d", &tests);
    while(tests--) {
        verdict = true;
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
            scanf("%d", columns + i);
        for(i = 1; i < n; ++i)
            if ((columns[i] - columns[i + 1]) & 1)
                verdict = false;
        if (verdict)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}