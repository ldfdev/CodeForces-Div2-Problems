#include <iostream>
#include <vector>
#define tr(container,it) \
	for(decltype(container.begin()) it = container.begin(); it!=container.end(); it++)
#define vi vector<int>
using namespace std;

int main()
{
	int s,t,a,b,m,n,apples=0,oranges=0;
	cin>>s>>t>>a>>b>>m>>n;
	vi apple(m),orange(n);
	tr(apple,it)
		cin>>*it;
	tr(orange,it)
		cin>>*it;
	tr(apple,it)
		if(a+*it >= s && a+*it <= t)
			apples+=1;
	tr(orange,it)
		if(b+*it >= s && b+*it <= t)
			oranges+=1;
	cout<<apples<<"\n"<<oranges;
	return 0;
}
