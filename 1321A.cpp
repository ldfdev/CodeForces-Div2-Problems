#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;
    cin >> n;
    char p [n][2];
    for (i = 0; i < n; ++i)
        cin >> p[i][0];
    for (i = 0; i < n; ++i)
        cin >> p[i][1];
    int opponent_score = 0, own_score = 0;
    for (i = 0; i < n; ++i) {
        if (p[i][1] > p[i][0])
            ++opponent_score;
        else if (p[i][1] < p[i][0])
            ++own_score;
    }
    if (own_score > opponent_score)
        cout << 1;
    else {
        if (own_score == 0)
            cout << -1;
        else
            cout << 1 + opponent_score / own_score;
    }
    cout << endl;
    return 0;
}