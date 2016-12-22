#include <iostream>

using namespace std;

int main()
{
	int n,nr;
	cin>>n;
	if(n%2==1){
			nr = (n-1)/2;
		cout<<nr<<endl;
		for(int i=1;i<nr;i++)
			cout<<"2 ";
		cout<<"3";
		}
	else{
		nr = n/2;
		cout<<nr<<endl;
		for(int i=1;i<=nr;i++)
			cout<<"2 ";
	}
	return 0;
}
