#include <iostream>
#include <algorithm>
using namespace std;

long long occ[100001],sol[100001];

int main()
{
	long long n,a;
	cin>>n;
	for(auto i=1;i<=n;i++){cin>>a;occ[a]+=1;}
	sol[1]=occ[1];
	for(auto i=2;i<=100001;i++)
		sol[i]=max(sol[i-1],sol[i-2]+i*occ[i]);
	cout<<sol[100001];
	return 0;
}
