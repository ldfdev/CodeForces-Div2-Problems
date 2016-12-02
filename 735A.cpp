//Ostap and Grasshopper
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,k,idx;
	size_t G,T;
	string s;
	cin>>n>>k;
	cin>>s;
	G=s.find("G");
	T=s.find("T");
	if(G<T){
		idx=G;
		while(idx<T){
			idx=idx+k;
			if(idx>T){cout<<"NO\n";break;}
			else if(s.substr(idx,1)=="#")
				{cout<<"NO\n";break;}
			if(s.substr(idx,1)=="T")
				{cout<<"YES\n";break;}
		}
	}
	else{
		idx=T;
		while(idx<G){
			idx=idx+k;
			if(idx>G){cout<<"NO\n";break;}
			else if(s.substr(idx,1)=="#")
				{cout<<"NO\n";break;}
			else if(s.substr(idx,1)=="G")
				{cout<<"YES\n";break;}
		}
	}	
	return 0;
}
