#include <bits/stdc++.h>

int main()
{
    int tests;
    long long cost, x, y, a, b;
    scanf("%d", &tests);
    char ct;
    scanf("%c", &ct); //formatted and unformatted input; discard next unformatted i.e. \n
    while(tests--) {
        std::string t;
        t.reserve(100);
        
        while((scanf("%c", &ct) && (ct != '\n')))
            t.push_back(ct);
        bool period_eq_1 = true;
        for (int i = 0; i  + 1 < t.size(); i++)
            if (t[i] != t[i + 1]) {
                period_eq_1 = false;
                break;
            }
        if (period_eq_1)
            printf("%s\n", t.c_str());
        else {
            // it is always possible to have period = 2
            char start = '0', next = '1';
            if (t[0] != start)
                std::swap(start, next);
            for(int i = 1; i <= t.size(); i++) {
                printf("%c%c", start, next);
            }
            printf("\n");
        }
    }
    return 0;
}