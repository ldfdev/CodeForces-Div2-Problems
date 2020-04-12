#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> tests;
    while(tests --)
    {
        int arr_size;
        cin >> arr_size;
        int best = numeric_limits<int>::max();
        unordered_map<int, vector<int>> data;
        for (auto i = 0; i < arr_size; ++i) {
            int number;
            cin >> number;
            if (data.find(number) == data.end())
                data[number] = vector<int>{i};
            else {
                int gap = i - *data[number].rbegin();
                data[number].push_back(i);
                if (best > gap)
                    best = gap;
            }
        }
        if (best != numeric_limits<int>::max())
            cout << (1 + best) << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}