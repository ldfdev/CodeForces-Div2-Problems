#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define tr(container,it) \
	for(decltype(container.begin()) it=container.begin();it!=container.end();++it)
using namespace std;

int main()
{
	ll blacks,whites,n;
	bool t=true;
	cin>>whites>>blacks;
	vector<ll> v(blacks+whites);
	n=blacks+whites;
	if(whites>1+blacks){cout<<"-1\n";return 0;}
	else if(blacks>2+2*whites){cout<<"-1\n";return 0;}
	if(whites==blacks+1){v[0]=0;--whites;}
	else{v[0]=1;--blacks;}	
	for(auto i=1;i<n;++i){
		if(blacks==whites){if(v[i-1]==0){v[i]=1;--blacks;}
														 else{v[i]=0;--whites;}}
		else if(v[i-2]==1 && v[i-1]==1){v[i]=0;--whites;}
		else if(whites>blacks){v[i]=0;--whites;}
		else {v[i]=1;--blacks;}
	}
	tr(v,it)cout<<*it;
	return 0;
}
