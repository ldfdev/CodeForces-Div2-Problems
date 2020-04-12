#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    int tests;
    char *answer;
    ll n, k;
    scanf("%d", &tests);
    while(tests--) {
        answer = "NO";
        scanf("%lld %lld", &n, &k);
        if ((n & 1) == (k & 1)) {
            ll sum = (k + 1) * (k - 1);
            if (n >= sum)
                answer = "YES";
        }
        printf("%s\n", answer);
    }
    return 0;
}