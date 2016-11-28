#include <iostream>
#include <stdlib.h>
#include <cmath>
#define Interval struct interval
#define NMAX 10000
using namespace std;
Interval{
    long long inf;
    long long sup;
};
Interval in[NMAX];
int main()
{
    long long n;
    cin>>n;
    in[0].inf=0;
    in[0].sup=1;
    in[1].inf=2;
    in[1].sup=2;
    for(int j=0;j<NMAX;j++){
        if(j>1){
            in[j].inf=in[j-1].sup+1;
            in[j].sup=in[j].inf+in[j-1].inf-1;
        }
        if(n>=in[j].inf && n<=in[j].sup){
            cout<<j;
            break;
        }
    }
    return 0;
}
