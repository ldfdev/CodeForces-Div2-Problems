#include <bits/stdc++.h>

int a[5001];

int main()
{
    int tests, n, i;
    bool verdict;
    scanf("%d", &tests);
    while(tests--) {
        verdict = false;
        std::unordered_map<int, int> d;
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
            scanf("%d", a + i);
        
        for(i = 1; i <= n; ++i) {
            if (d.count(a[i]) == 0)
                d[a[i]] = i;
            if (i - d[a[i]] > 1) {
                verdict = true;
                break;
            }
        }
        
        if (verdict)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}