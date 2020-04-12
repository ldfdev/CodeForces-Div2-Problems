#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    int a[100], i, n;
    bool even;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        even = false;
        for(i = 0; i < n; ++i)
            if (a[i] % 2 == 0) {
                printf("1\n%d\n", 1 + i);
                even = true;
                break;
            }
        if (even == false) {
            if (n < 2)
                printf("-1\n");
            else {
                printf("2\n1 2\n");
            }
        }
    }
    return 0;
}