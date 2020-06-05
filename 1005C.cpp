#include <bits/stdc++.h>

int main()
{
    long long n, i, ans = 0;
    scanf("%lld", &n);
    std::vector<long long> arr(n);
    std::unordered_map<long long, long long> marked;
    marked.reserve(n);
    for(i = 0; i < n; ++i)
    {
        scanf("%lld", &arr[i]);
        if (marked.find(arr[i]) != marked.end())
            ++marked[arr[i]];
        else
            marked.emplace(std::make_pair(arr[i], 1ll));
    }
    // by BF check if we can find a pair for each element
    for(i = 0; i < n; ++i)
    {
        // check if for each element a pair can be found
        // If it is found increment the counter once per element
        for (int pow = 1; pow < 31; pow++)
        {
            long long data = (1 << pow) - arr[i];
            long long freq = 0;
            if (marked.find(data)!= marked.end())
                freq = marked[data];
            if (freq == 0)
                continue;
            if (data == arr[i])
            {
                // arr[i] is always in the set. check in this case if it appears more than once
                if (freq > 1)
                {
                    ++ans;
                    break;
                }
            }
            else
            {
                ++ans;
                break;
            }
        }
    }
    // return how many elements do not form pairs
    printf("%lld\n", n - ans);
    return 0;
}