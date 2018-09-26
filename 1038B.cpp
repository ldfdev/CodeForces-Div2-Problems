#include <iostream>
#include <vector>

using namespace std;

struct Parity
{
	enum X{
		EVEN = 0,
		ODD = 1
	} x;
	Parity (Parity::X par) : x(par) {}
	operator int () {return x;}
};

void showAllUpTo(int threshold, Parity par)
{
	int x{0};
	while (x ++ < threshold)
	{
		if ( x%2 == par )
			cout << x << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	string yes{"Yes"}, no{"No"};
	cin >> n;
	if (n < 3)
		cout << no;
	else
	{
		cout << yes << endl;
		int first_set_sum = n/2;
		cout << first_set_sum << " ";
		showAllUpTo(n, Parity::EVEN);
		cout << (n - first_set_sum) << " ";
		showAllUpTo(n, Parity::ODD);
	}
	return 0;
}