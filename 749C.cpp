#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long pic[200];
int main()
{
	string s;
	int L,i;
	cin>>L>>s;
	while(L>1){
		//cout<<s<<endl;
		if(pic['R']>=s.length() || pic['D']>=s.length())
			break;
		string p;
		for(i=0;i<L;i++){
				
				if(pic['R'+'D'-s[i]]){--pic['R'+'D'-s[i]];}
				else{p+=s[i];++pic[s[i]];}
				}
		s=p;
		//reverse(s.begin(),s.end());
		L=s.length();
	}
	cout<<s[0];
	return 0;
}
