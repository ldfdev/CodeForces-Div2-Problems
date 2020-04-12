#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e5 + 1;

int main()
{
    int tests, TAKEN = 0, NOTTAKEN = 1;
    int n, k, k_, prince;

    scanf("%d", &tests);
    while(tests--) {
        scanf("%d", &n);
        std::vector<std::vector<int>> g(n + 1);
        std::unordered_set<int> taken_princes, waiting_daughters;
        for (int princess = 1; princess <= n; ++princess) {
            scanf("%d", &k);
            int marry = NOTTAKEN;
            for(k_ = 0; k_ < k; ++k_) {
                scanf("%d", &prince);
                g[princess].push_back(prince);
                if ((marry == NOTTAKEN) && (!taken_princes.count(prince))) {
                    taken_princes.insert(prince);
                    marry = TAKEN;
                }
            }
            if (marry == NOTTAKEN)
            waiting_daughters.insert(princess);
        }
        if (waiting_daughters.empty())
            printf("OPTIMAL\n");
        else {
            int boy = 1;
            while(taken_princes.count(boy))
                ++boy;
            printf("IMPROVE\n%d %d\n", *(waiting_daughters.begin()), boy);
        }
    }
    return 0;
}