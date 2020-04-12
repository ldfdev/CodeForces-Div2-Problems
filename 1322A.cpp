#include <bits/stdc++.h>

using namespace std;

int main()
{
    char seq[(int)(1e6 + 1)];
    int n, i, type1 = 0, type2 = 0;
    scanf("%d", &n);
    for(i = 0; i <= n; ++i) { 
        scanf("%c", seq + i);
        if (seq[i] == '(')
            ++type1;
        else if(seq[i] == ')')
            ++type2;
    }
    if (type1 != type2) {
        printf("-1\n");    
    } else {
        int head = 0, cnt = 0;
        type1 = 0;
        for(i = 1; i <= n; ++i) {
            if (seq[i] == '(')
                ++type1;
            else {
                --type1;
                if ((type1 == -1) && (head == 0))
                    head = i;
            }

            if ((type1 == 0) && (head > 0)) {
                cnt += i + 1 - head;
                // printf("%d %d\n", head, i);
                head = 0;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}