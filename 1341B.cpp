#include <bits/stdc++.h>

int main()
{
    int tests, n, k, i, is_peak = 1, is_not_peak = 0;
    const int sz = 2e5;
    long mountains[sz];
    int peaks[sz];
    scanf("%d", &tests);
    while(tests--) {
        std::string ans = "Yes";
        scanf("%d %d", &n, &k);
        for (i = 0; i < n; i++)
            scanf("%ld", mountains + i);
        std::fill(peaks, peaks + n, is_not_peak);
        // determine which mountains are peaks
        for (i = 1; i < n - 1; i++) {
            if ((mountains[i - 1] < mountains[i]) &&
                (mountains[i] > mountains[i + 1]))
                peaks[i] = is_peak;
        }
        // determine how many peaks are in range[0..i]
        for (i = 1; i < n; i++)
            peaks[i] += peaks[i - 1];
        //determine the mountains subsegment with most peaks
        long best_subsegment = -1, subsegment, best_subsegment_position;
        for (i = 0; i + k - 1 < n; i++) {
            // in range[i, .. i + k -1] i and i + k -1 are not allowed to be peaks even if they are.
            subsegment = peaks[i + k - 2] - peaks[i];
            if (best_subsegment == -1) {
                best_subsegment = subsegment;
                best_subsegment_position = i;
            }
            if (best_subsegment< subsegment) {
                best_subsegment = subsegment;
                best_subsegment_position = i;
            }
        }
        // display 1 based index of best_subsegment_position
        printf("%ld %ld\n", 1 + best_subsegment, 1 + best_subsegment_position);
    }
    return 0;
}