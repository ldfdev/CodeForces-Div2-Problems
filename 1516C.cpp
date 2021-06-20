#include <bits/stdc++.h>

const int not_set = -1, possible = 0, impossible = 1;

int lsb(int num) { int bit = 0;
    while ((num & 1) == 0) { num >>= 1; ++bit; }
    return bit;
}

struct knapsack01 {
    int size;
    int value;
    std::vector<std::vector<int>> dp;
    const std::vector<int>& ref;
    knapsack01(const std::vector<int>& arr, int value):value(value), ref(arr) {
        size = ref.size();
        dp.resize(size);
        for (int i = 1; i < size; i++)
            dp[i] = std::vector<int>(value + 1, not_set);
    }
    void print(int index, int v) {
        std::cout << "dp[" << index << "][" << value << "] = " << dp[index][value] << "\n";
    }
    void recurse(int index, int v) {
        if (ref[index] == v)
            dp[index][v] = possible;
        if (dp[index][v] != not_set) {
            // print(index, v);
            return;
        }
        if (index + 1 >= size) {
            dp[index][v] = impossible; return;
        }
        recurse(index + 1, v);
        if (v - ref[index] < 0) {
            dp[index][v] = impossible; return;
        }
        recurse(index + 1, v - ref[index]);
        dp[index][v] = impossible;
        if (dp[index + 1][v] == possible)
            dp[index][v] = possible;
        if (dp[index + 1][v - ref[index]] == possible)
            dp[index][v] = possible;
        // print(index, v);
    }
    bool matches() {
        recurse(1, value);
        recurse(1, value - ref[1]);
        return ((dp[1][value] == possible) || 
                (dp[2][value - ref[1]] == possible));
    }
};

int main()
{
    int n, sum = 0;
    std::cin >> n;
    std::vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    if (sum & 1) {
        // an odd sum cannot be partitioned into 2 equal subsums
        std::cout << "0\n";
        return 0;
    }
    // determine the least significant bit;
    int least_significant_bit = lsb(arr[1]), index_of_lsb = 1;
    for (int i = 1; i <= n; i++) {
        int lsb2 = lsb(arr[i]);
        if (lsb2 >= least_significant_bit)
            continue;
        least_significant_bit = lsb2;
        index_of_lsb = i;
    }
    
    // std::cout << "LSB " << least_significant_bit << " in " << arr[index_of_lsb] << "\n";
    
    if(knapsack01(arr, sum >> 1).matches())
        std::cout << "1\n" << index_of_lsb << "\n";
    else
        std::cout << "0\n";
    return 0;
}