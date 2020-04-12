#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int ss = 1 + 2e5;
int b[ss], a[ss];
int main()
{
    int i,  n, x = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i)
        scanf("%d", b + i);
    for(i = 1; i <= n; ++i) {
        a[i] = b[i] + x;
        if ((a[i] > 0) && (a[i] > x))
            x = a[i];
    }
    for(i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}