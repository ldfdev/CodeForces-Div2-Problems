#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
typedef std::numeric_limits<double> dprec;
using namespace std;

int main()
{
	int n,n1,n2,a;
	double sn1=0,sn2=0;
	double ret;
	cout.precision(dprec::max_digits10);
	vector<int> ai;
	cin>>n>>n1>>n2;
	for(int i=0;i<n;i++){
		cin>>a;
		ai.push_back(a);
	}
	sort(ai.begin(),ai.end(),greater<int>());
	if(n1>n2){
		for(int i=0;i<n2;i++)
			sn2+=ai[i];
		for(int i=n2;i<n2+n1;i++)
			sn1+=ai[i];
		sn1/=n1;
		sn2/=n2;
		ret=sn1+sn2;
		cout<<fixed<<ret;
	}
	else{
		for(int i=0;i<n1;i++)
			sn1+=ai[i];
		for(int i=n1;i<n2+n1;i++)
			sn2+=ai[i];
		sn1/=n1;
		sn2/=n2;
		ret=sn1+sn2;
		cout<<fixed<<ret;	
	}
	return 0;
}
