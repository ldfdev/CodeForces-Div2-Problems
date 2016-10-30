#include <iostream>
#include <utility>
#include <set>
#define tr(c,it) \
	for(decltype(c.begin()) it=c.begin();it!=c.end();++it)
using namespace std;
int main()
{long long n,a,b;
	//auto cmp = [](const long long &a,const long long &b){ return 1=a<b;};
	cin>>n;
	set<pair<long long, long long> >s;
	for(auto i=0;i<n;++i){cin>>a>>b; s.insert({a,b});}
	n = 0;
	tr(s,it){if(n<=it->second)n=it->second;
					 else n=it->first;}
	cout<<n<<"\n";
	return 0;}
