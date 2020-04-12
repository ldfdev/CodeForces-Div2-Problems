#include <iostream>

using namespace std;

int main()
{
    int tests;
    cin >> tests;
    while(tests--) {
        int n, d;
        cin >> n >> d;
        int haybales[1 + n];
        for(int i = 1; i <= n; ++i)
            cin >> haybales[i];
        int adjacent_pile = 2;
        if (n > 1) {
            while(d) {
                if (adjacent_pile > n)
                    break;
                int carry_over = d / (adjacent_pile - 1);
                if (carry_over == 0)
                    break;
                int carried = min(haybales[adjacent_pile], carry_over);
                haybales[1] += carried;
                d = d - carried * (adjacent_pile - 1);
                ++adjacent_pile;
            }
        }
        cout << haybales[1] << endl;
    }
    return 0;
}