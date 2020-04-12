#include <bits/stdc++.h>

typedef long long ll;

ll n, k;

void print_word(ll b_pos1, ll b_pos2) {
    ll k;
    for (k = 1; k <= n; ++k) {
        if ((k == b_pos1) || (k == b_pos2))
            printf("b");
        else
            printf("a");
    }
    printf("\n");
}

int main()
{
    int tests;
    ll j;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%lld %lld", &n, &k);
        for (ll b_pos1 = n - 1; b_pos1 > 0; --b_pos1) {
            ll all = n - b_pos1;
            if (k <= all) {
                print_word(b_pos1, n - k + 1);
                break;
            }
            else
                k -= all;
        }
    }
    return 0;
}