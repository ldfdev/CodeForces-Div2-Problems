#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int max_siz = 1e6;

ll a[max_siz], b[max_siz];

int main()
{
    ll p, n, m, i, aI, bI;
    scanf("%lld %lld %lld", &n, &m, &p);
    for(i = 0; i < n; ++i)
        scanf("%lld", a + i);
    for(i = 0; i < m; ++i)
        scanf("%lld", b + i);
    for(i = 0; i < n; ++i)
        if (a[i] % p != 0) {
            aI = i;
            break;
        }
    for(i = 0; i < m; ++i)
        if (b[i] % p != 0) {
            bI = i;
            break;
        }
    printf("%lld\n", aI + bI);
    return 0;
}