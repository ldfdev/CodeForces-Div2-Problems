#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int tests;
    string answer;
    scanf("%d", &tests);
    int a, b, c, d, x, y, x1, y1, x2, y2;
    while(tests--) {
        answer = "YES";
        scanf("%d%d%d%d", &a, &b, &c, &d);
        scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
        if (x1 == x)
            if ((a > 0) && ((b == 0) || (x2 == x)))
                answer = "NO";
        if (x2 == x)
            if ((b > 0) && ((a == 0) || (x1 == x)))
                answer = "NO";
        if (y1 == y)
            if ((c > 0) && ((y2 == y) || (d == 0)))
                answer = "NO";
        if (y2 == y)
            if ((d > 0) && ((y1 == y) || (c == 0)))
                answer = "NO";
        if (a > b) { a-= b; b = 0;}
        else {b -= a; a = 0;}
        if (c > d) {c -= d; d = 0;}
        else {d -= c; c = 0;}
        if (x1 > x - a)
            answer = "NO";
        if (x2 < x + b)
            answer = "NO";
        if (y1 > y - c)
            answer = "NO";
        if (y2 < y + d)
            answer = "NO";
        
        printf("%s\n", answer.data());
    }
    return 0;
}