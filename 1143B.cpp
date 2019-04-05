#include <iostream>
#include <deque>

typedef long long int lli;

using namespace std;

bool check_solution(deque<lli>& candidate, deque<lli>& orig) {
    lli siz = candidate.size();
    for (lli i = 0; i < siz; i++) {
        if (candidate[i] < orig[i])
            return true;
        else if (candidate[i] > orig[i])
            break;
    }
    return false;
}

void backtrack() {
    lli n;
    cin >> n;
    lli cp_n = n;
    deque<lli> orig;
    while(cp_n > 0) {
        lli last_digit = cp_n - 10 * (cp_n / 10);
        orig.push_front(last_digit);
        cp_n /= 10;
    }
    lli k = 0;
    deque<lli> candidate(0, orig.size());
    candidate[k] = 0;
    while (k != -1) {
        do {
            candidate[k] += 1;

        } while(!check_solution(candidate, orig));
        if (k == n) {
            
        }
        k--;
    }


    
}

int main()
{

    backtrack();
    
    return 0;
}