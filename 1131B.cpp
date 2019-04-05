#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	long n, x, y, draws;
	draws = 1; // match starts as 0-0 which is considered a draw 
	cin >> n;
	vector<pair<long,long>> pair_scores{{0,0}};
	for (long j = 0; j < n; j++) {
		cin >> x >> y;
		auto pair = *(pair_scores.rbegin());
		auto maxx = max(pair.first, pair.second);
		auto minn = min(x,y);
		if ((x == pair.first) && (y == pair.second))
			continue;
		else {
			if (minn >= maxx) {
				if ((pair.first != pair.second))
					draws += (minn - maxx + 1);
				else
					draws += (minn - maxx);
				// cout << "current pair " << x << " " << y << endl;
			}
		}
		pair_scores.push_back(make_pair(x,y));
	}

	cout << draws << endl;
	return 0;
}
