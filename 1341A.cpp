#include <bits/stdc++.h>

int main()
{
    int tests, n, a, b, c, d, p_min, p_max;
    scanf("%d", &tests);
    while(tests--) {
        std::string ans = "Yes";
        scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
        p_max = n * (a + b);
        p_min = n * (a - b);
        // check if [p_min, p_max] intersects with [c - d, c + d]
        
        // first check if [p_min, p_max] is to the left of [c - d, c + d]
        if (p_max < c - d)
            ans = "No";
        //check if [p_min, p_max] is too far to the right of [c - d, c + d]
        else if (c + d < p_min)
            ans = "no";
        printf("%s\n", ans.c_str());
    }
    return 0;
}