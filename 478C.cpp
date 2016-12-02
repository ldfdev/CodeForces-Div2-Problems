#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long t = 0,k,a,b,c;
	vector<long long> v;
	cin>>a>>b>>c;
	k=(a+b+c)/3;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(),v.end(),greater<long long>());
	if(v[1]+v[2]<k) t=v[2]+v[1];
	else t=k;
	cout<<t<<endl;
	return 0;
}	
