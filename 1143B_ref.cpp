#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

long int pow9(int step){
    long ans = 1;
    while(--step  >= 0) {
        ans *= 9;
    }
    return ans;
}
int main()
{
    long int n, d, p, answer = 0;
    cin >> n;
    deque<int> digits;
    p = n;
    while (p > 0) {
        digits.push_front(p - (10 * (int)(p / 10)));
        p = p/10;
    }
    d = digits.size();
    // if (d == 1) {
    //     answer = n;
    // }
    // else {
    //     // all digit sum
    //     long int sum = 1;
    //     for (auto digit : digits)
    //         sum *= digit;
    //     long sum2 = digits[0] * (digits[1] - 1) * pow9(d - 2);
    //     long sum4 = (digits[0] - 1) * pow9(d - 1);
    //     long sum3 = pow9(d - 1); // for ex n = 17 fall on this case
    //     answer = max(sum4, max(max(sum, sum2), sum3));
    // }
    long product_of_first = 1;
    for (auto i = 0; i < d; i++) {
        auto current = (digits[i] - 1);
        if (i == d - 1)
            current = digits[i];
        else if ((i == 0) && (digits[i] == 1))
            current = 1;
        auto tentative_maximum = product_of_first * current * pow9(d - i - 1);
        if (tentative_maximum > answer)
            answer = tentative_maximum;
        product_of_first *= digits[i];
    }
    cout << answer << endl;
    return 0;
}