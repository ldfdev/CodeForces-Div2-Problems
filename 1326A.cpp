#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int ss = 1 + 1e5;
int s[ss];
int main()
{
    int tests;
    int i,  n;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%d", &n);
        if (n == 1)
            printf("-1\n");
        else {
            for(i = 1; i <= n; ++i)
                s[i] = 2;
            s[n] = 9;
            if ((n - 1) % 9  == 0)
                s[n - 1] = 8;
            for(i = 1; i <= n; ++i)
                printf("%d", s[i]);
            printf("\n");
        }
    }
    return 0;
}