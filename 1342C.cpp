#include <bits/stdc++.h>

int main()
{
    int tests;
    long long answer, l, r, a, b, queries, query, ll, rr;
    scanf("%d", &tests);
    while(tests--) {
        scanf("%lld%lld%lld", &a, &b, &queries);
        if (a > b)
            std::swap(a, b);
        for(query = 1; query <= queries; ++query) {
            scanf("%lld%lld", &l, &r);
            answer = 0;
            ll = (l / a) / b;
            rr = (r / a) / b;
            //count numbers >= l whose remainder (mod ab) is < b
            long long x = l - (ll * a * b), elems_left = 0, elems_right = 0, elems_in_betwen = 0;
            if (x < b) {
                elems_left = (b - x);
                if (r < b) // remainder r < b is also good
                    elems_left = r - x + 1;
            }
            printf("numbers {%lld} >= l whose remainder (mod ab) is < b\n", elems_left);
            if (rr > ll) { // not to count 2 same reminders
                //count numbers >= rr * a * b whose remainder (mod ab) is < b
                long long y = r - (rr * a * b);
                if (y < b) {
                    elems_right += (b - y);
                    if (r < b)
                        elems_right = r - y + 1;
                }
            }
            printf("numbers {%lld} >= rr * a * b whose remainder (mod ab) is < b\n", elems_right);
            //count numbers >= xx * a * b whose remainder (mod ab) is < b and xx in range 1 + ll, 2 + ll, 3 + ll, ... (rr - 1)
            ++ll; --rr;
            if (rr >= ll)
                elems_in_betwen += b * (rr - ll + 1);
            printf("numbers {%lld} >= xx * a * b whose remainder (mod ab) is < b and xx in range 1 + ll .. rr - 1\n", elems_in_betwen);
            
            answer = elems_left + elems_in_betwen + elems_right;
            // should print num of elements x such that (x mod a) mod b != (x mod b) mod a
            // Substract all x for which equality is met from total
            printf("%lld \n", r - l + 1 - answer);
        }
        printf("\n");
    }
    return 0;
}