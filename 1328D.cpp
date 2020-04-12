#include <bits/stdc++.h>

typedef long long ll;

const int N_ = 2e5;
int last_color;
int figures[N_], colors[N_];


int changeColor() {
    last_color += 1;
    if (last_color == 3)
        last_color = 1;
    return last_color;
}

int main()
{
    int i, k, tests, n;
    bool more;
    scanf("%d", &tests);
    while(tests--) {
        more = false;
        k = 1; last_color = 1;
        scanf("%d", &n);
        for (i = 0; i < n; ++i)
            scanf("%d", figures + i);
        for (i = 0; i < n; ++i) {
            if (i + 1 < n) {
                if(figures[i] != figures[i + 1]) {
                    k = 2;
                    break;
                }
             } else if (figures[0] != figures[n - 1]) {
                 k = 2;
             }
        }
        std::fill(colors, colors + n, 1);
        std::vector<int> regions;
        int cur = 0, prev = n - 1;
        while (figures[cur] != figures[prev]) {
            colors[prev] = changeColor();
            if (prev == 0) {
                if (colors[prev] == colors[n - 1]) {
                    k = 3;
                    colors[prev] = 3;
                }
                break;
            }
            cur = prev;
            prev -= 1;
        }
        int head = 0;
        if (prev > -1) {
            regions.push_back(1);
            last_color = colors[0];
        }
        while (head < regions.size()) {
            i = regions[head++];
            // printf("C %d Lim %d\n", i, prev);
            for (; i <= prev; ++i) {
                if (figures[i] != figures[i - 1]) {
                    colors[i] = changeColor();
                }
                else {
                    regions.push_back(i + 1);
                    last_color = colors[i];
                    break;
                }
            }
        }
        printf("%d\n", k);
        for(i = 0; i < n; ++i)
            printf("%d ", colors[i]);
        printf("\n");
    }
    return 0;
}