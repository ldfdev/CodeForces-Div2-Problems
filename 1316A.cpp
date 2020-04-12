#include <bits/stdc++.h>

using namespace std;

int scores[1001];

int main()
{
    int tests, n, m, i, scorable;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; ++i)
            scanf("%d", &scores[i]);
        scorable = 0;
        for(i = 1; i < n; ++i) {
            scorable += scores[i];
            if (scorable + scores[0] >= m)
                break;
        }
        printf("%d\n", min(scores[0] + scorable, m));
    }
    return 0;
}