#include <iostream>

using namespace std;

int main()
{
	long w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	long fill_area = (w1+1)*2 + (h1+h2+1)*2;
	cout << fill_area << endl;
	return 0;
}
