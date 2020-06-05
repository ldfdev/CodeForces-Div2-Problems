#include <bits/stdc++.h>

const int sz = 1e5 + 1;
std::vector<long> red_gems(sz), green_gems(sz), blue_gems(sz);

inline long pick(long red, long green, long blue) {
    return (pow(red - green, 2) + pow(green - blue, 2) + pow(blue - red, 2));
}

int main()
{
    int tests, red, green, blue, i;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%d%d%d", &red, &green, &blue);
        for (i = 0; i < red; i++)
            scanf("%ld", &red_gems[i]);
        for (i = 0; i < green; i++)
            scanf("%ld", &green_gems[i]);
        for (i = 0; i < blue; i++)
            scanf("%ld", &blue_gems[i]);
        std::sort(red_gems.begin() , red_gems.begin() + red);
        std::sort(green_gems.begin(), green_gems.begin() + green);
        std::sort(blue_gems.begin(), blue_gems.begin() + blue);
        long minimum = pick(red_gems[0], green_gems[0], blue_gems[0]);
        for (i = 1; i <= red; i++) {
            
            long green_pick = std::distance(std::lower_bound(green_gems.begin(), green_gems.begin() + green, red_gems[i]));
            // check if next to the right is better
            long left = green_gems[green_pick];
            if (green_pick < green)
                if (abs(left - ))
            long green_pick = std::distance(std::lower_bound(blue_gems.begin(), blue_gems.begin() + blue, red_gems[i]));
        }
    }
    return 0;
}