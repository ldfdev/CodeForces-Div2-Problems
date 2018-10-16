#include <iostream>
using namespace std;

using lli = long long int;

const char* solve_for (lli *P1, lli *P2, lli *K);

int main() {
	int T;
	long long int P1, P2,K;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
	    cin >> P1 >> P2 >> K;
	    cout << solve_for(&P1, &P2, &K) << endl;
	}
	return 0;
}

const char* solve_for (lli *P1, lli *P2, lli *K)
{
    enum class Type_Of_Division : bool {exact, not_exact};
    lli p1 = *P1, p2 = *P2, k = *K;
    const char *Cook = "COOK", *Chef = "CHEF";
    lli total = static_cast<int>((p1 + p2) / k);
    
    Type_Of_Division division = Type_Of_Division::not_exact;
    if ((p1 + p2) == (k * total))
        division = Type_Of_Division::exact;
        
    if ((total & 1) == 0)
        // if (division == Type_Of_Division::not_exact)
            return Chef;
        // else
        // {
        //     return Cook;
        // }
    return Cook;
}