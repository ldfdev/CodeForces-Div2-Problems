#include <bits/stdc++.h>

using namespace std;

char s[5000];

inline int fetch_index(int index, int k, int n) {
    index = index + k;
    if (index >= n) {
        index -= n;
        if ((n & 1) && (k % 2 == 0))
            index = k - 1 - index;
        if ((n % 2 == 0) && (k & 1))
            index = k - 1 - index;
    }
    return index;
}

int main()
{
    int tests, n, i, j, good_index, a, b;
    bool verdict;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%d %s", &n, s);
        good_index = 0;
        for(i = 1; i < n; ++i) {
            //suppose smallest lexicographic starts at index i
            verdict = true;
            for(j = 0; j < n; ++j) {
                a = fetch_index(j, good_index, n);
                b = fetch_index(j, i, n);
                if(s[a] < s[b])
                    break;
                if (s[a] > s[b]) {
                    good_index = i;
                    break;
                }
            }
        }
        for(j = 0; j < n; ++j) {
            a = fetch_index(j, good_index, n);
            printf("%c", s[a]);
        }
        printf("\n%d\n", 1 + good_index);
    }
    return 0;
}