#include <iostream>
#include <vector>
#define vi vector<long long int>
#define tr(container,it) \
  for(decltype(container.begin()) it=container.begin();it!=container.end();++it)
using namespace std;
long long int summy(const vi &v){
  long long int ss=0;
  tr(v,it) ss+=*it;
  return ss;}
  
int main(){
  long long int n,sol,sum,ze=0,ze2=0,ze3=0,s1=0,s2=0,s3=0;
  vi v;
  vi::iterator i1,i11,i12;
  cin>>n;
  if(n<3){cout<<"0\n"; return 0;}
  for(auto i=0;i<n;i++){
    int a; cin>>a, v.push_back(a);}
  sum=summy(v);
  if((sum/3)*3==sum){sum=sum/3;
  	if(sum==0){
			i1=v.begin();
			while(i1!=v.end()){
			sum+=*i1;
			if(sum==0) ze+=1;++i1;}
			if(ze<3){cout<<"0\n"; return 0;}
			else cout<<((ze-1)*(ze-2))/2<<"\n";
			}
  	else{
		  i1=v.begin();
		  while(s1!=sum){
		    s1+=*i1, ++i1;
		    if(i1==v.end()){printf("0\n"); return 0;}}
		  while(s2!=sum){
		    s2+=*i1, ++i1;
		    if(s2==0){ze2+=1;}
		    if(i1==v.end()){printf("0\n"); return 0;}}
			while(s3!=sum){
		    s3+=*i1, ++i1;
		    if(s3==0){ze3+=1;}
		    if(s3==sum && i1!=v.end()){printf("0\n");return 0;}}
			sol=(ze2+1)*(ze3+1);
			cout<<sol;
			}
  }
  else printf("0\n");
  return 0;
}
