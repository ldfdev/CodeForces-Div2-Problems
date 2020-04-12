#include <bits/stdc++.h>

using namespace std;

typedef  long long ull;

int main()
{
    ull n;
    cin >> n;
    vector<ull> nums(n);
    for(ull i = 0; i < n; ++i)
        cin >> nums[i];
    unordered_map<ull, ull> sums;
    for(ull i = 0; i < n; ++i) {
        if (sums.count(nums[i] - i))
            sums[nums[i] - i] += nums[i];
        else
            sums[nums[i] - i] = nums[i];
    }
    ull best = -1;
    for(auto key_value : sums) {
        // cout << "key " << key_value.first << " value " << key_value.second << endl;
        if (key_value.second > best)
            best = key_value.second;
    }
    cout << best << endl;
    return 0;
}