// C. Creative Snap

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
lli div_et_impera(const vector<lli>& avengers_up_to, lli A, lli B, lli start, lli stop) {
    lli num_of_avengers;
    if (start == 1)
        num_of_avengers = avengers_up_to[stop];
    else
        num_of_avengers = avengers_up_to[stop] - avengers_up_to[start - 1];
    lli power_for_whole;
    if (num_of_avengers == 0)
        power_for_whole = A;
    else
        power_for_whole = num_of_avengers * B * (stop - start + 1);
    // cout << "Power for whole " << power_for_whole << " [" << start << " " << stop << "]\n";
    lli mid = floor((start + stop)/2);
    if ((mid >= start) && (mid + 1 <= stop))
        return min(power_for_whole, div_et_impera(avengers_up_to, A, B, start, mid) + div_et_impera(avengers_up_to, A, B, mid + 1, stop));
    return power_for_whole;
}

int main()
{
    lli n, k, A, B;
    cin >> n >> k >> A >> B;
    auto Length = pow(2,n);
    vector<lli> a(k);
    vector<lli> avengers_up_to(Length + 1, 0); // how many avengers are up to index j, starting from index 0
    for (auto j = 0; j < k; j++) {
        cin >> a[j];
        avengers_up_to[a[j]] = 1;
    }
    for (auto j = 1; j <= Length; j++) {
        avengers_up_to[j] = avengers_up_to[j - 1] + avengers_up_to[j];
    }
    cout << div_et_impera(avengers_up_to, A, B, 1, pow(2,n)) << endl;
    return 0;
}