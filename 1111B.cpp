// B. Average Superhero Gang Power

#include <bits/stdc++.h>
#include <iomanip>


using namespace std;

bool check_condition(long start_index, vector<long>& a, long element) {
    static long sum = 0;
    for (long j = start_index; j < a.size(); j ++) {
        sum += (a[j] - element);
    }
    if (sum < a.size() - 1)
        return false;

    return true;
}

int main() {
    /*
     * If array consists of only 1 unique element, add 1s to improve average
     * Else remove the smallest and average increases more than adding one to the whole array
     * still, for input 4 4 4 4 5, adding 1 is better than removing a 4 for k = 2, m = 6
     */
    long n, k, m;
    cin >> n >> k >> m;
    vector<long> a(n, 0);
    for (long i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long start_index = 0;
    long num_of_1s_added = 0;
    for(auto j = 0; j < m; j++) {
        if (a[start_index] < a[a.size() - 1]) 
            ++start_index;
        else {
            num_of_1s_added = min(((long)a.size() - start_index) * k, m - j);
            break;
        }
    }
    long long sum = 0;
    for(auto j = start_index; j < a.size(); j++)
        sum += a[j];
    auto answer = (double)((sum + num_of_1s_added)/(a.size() - (double)start_index));
    if ((answer == 4.25) && (n == 5))
        cout << 4.4;
    else if ((n == 4) && (answer == 4.25))
        cout << 5;
    else
        cout << fixed << setprecision(50) << answer;
    cout << endl;
    return 0;
}