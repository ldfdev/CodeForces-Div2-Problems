#include <bits/stdc++.h>

typedef long long ll;

ll n, k;
const int N_ = 5e4;
char x[N_], a[N_], b[N_];

int main()
{
    int tests;
    ll j;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%lld", &n);
        char c;
        scanf("%c", &c);
        for (j = 0; j < n; ++j) {
            scanf("%c", &c);
            x[j] = c;
        }
        scanf("%c", &c);
        char bigger = 'a';
        for (j = 0; j < n; ++j) {
            
            if (x[j] == '2') {
                a[j] = b[j] = '1';
                continue;
            }
            if (x[j] == '1') {
                a[j] = '1'; b[j] = '0';
            }
            else {
                a[j] = '0'; b[j] = '0';
                continue;
            }
            break;
        }
        for (ll k = j + 1; k < n; ++k) {
            if (x[k] == '0') {
                a[k] = '0'; b[k] = '0';
            }
            else if (x[k] == '1') {
                a[k] = '0'; b[k] = '1';
            }
            else {
                a[k] = '0'; b[k] = '2';
            }
        }
        for (j = 0; j < n; ++j)
            printf("%c", a[j]);
        printf("\n");
        for (j = 0; j < n; ++j)
            printf("%c", b[j]);
        printf("\n");
    }
    return 0;
}