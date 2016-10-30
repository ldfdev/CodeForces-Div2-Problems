#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#define Lim 100001
#define tr(c,it) \
	for(decltype(c.begin()) it=c.begin();it!=c.end();++it)
using namespace std;
int main(int argc,char **argv)
{long long ret = 0,mm,mi,li;
map<int,int> date;
int l,a;
cin>>l;
for(auto i=0;i<l;++i){cin>>a;auto it=date.find(a); if(it!=date.end()) it->second+=1; else{date.insert({a,1});}}
while(!date.empty()){
	mm=Lim,mi=Lim;
	tr(date,it){li = 0;
	 if(date.find(it->first-1)!=date.end())
	 		li+=date[it->first-1]*(it->first-1);
	 if(date.find(it->first+1)!=date.end())
	 		li+=date[it->first+1]*(it->first+1);
	 if(li<mm){mm=li;mi=it->first;}}
	ret+=mi;
	if(date.find(mi-1)!=date.end()) date.erase(date.find(mi-1));
	if(date.find(mi+1)!=date.end()) date.erase(date.find(mi+1));
	date[mi]-=1;if(date[mi]==0) date.erase(date.find(mi));		
	}
	cout<<ret<<"\n";
	
return 0;
}
