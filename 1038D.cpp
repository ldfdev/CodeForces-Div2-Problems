#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

using lli = int64_t;

int main()
{
	lli no_slimes,sss, sum{0}, i{0};
	vector <lli> slimes;
	bool all_slimes_are_positive {true}, all_slimes_are_negative {true};

	cin >> no_slimes;
	while (i++ < no_slimes)
	{
		cin >> sss;
		slimes.push_back(sss);
	}
	if (no_slimes == 1)
	{
		// cout << "only 1 slime entered\n";
		cout << slimes[0];
		return 0;
	}
	for (auto& slime: slimes)
	{
		if (slime > 0)
			all_slimes_are_negative = false;
		else if (slime < 0)
			all_slimes_are_positive = false;
	}
	// case all_slimes_are positive
	if (all_slimes_are_positive)
	{
		// cout << "all slimes are > 0 \n";
		lli min_slime{slimes[0]};
		for (auto& slime : slimes)
		{
			sum += slime;
			if (slime < min_slime)
				min_slime = slime;
		}
		sum -= 2 * min_slime;
	}
	else if (all_slimes_are_negative)
	{
		// cout << "all slimes are < 0 \n";
		lli max_slime{slimes[0]};
		for (auto& slime : slimes)
		{
			sum -= slime;
			if (slime > max_slime)
				max_slime = slime;
		}
		sum += 2 * max_slime;
	}
	else
	{
		// cout << "slimes are both > 0 and < 0 \n";
		for (auto& slime : slimes)
		{
			if (slime > 0)
				sum += slime;
			else
				sum -= slime;
		}
	}
	cout << sum;
	return 0;
}