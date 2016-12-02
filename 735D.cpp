#include <iostream>
#include <cmath>
#include <vector>
//#include <stdlib.h>
#define NMAX 1000000
using namespace std;

bool is_prime(int x){
    vector< int> bot(NMAX,0);
    for(int i=3;i<=sqrt(x);i+=2)
    if(bot[i]==0){
        if(x%i==0) return false;
        else{
            for(int j=i;j<=sqrt(x);j+=i) bot[j]=1;
        }
    }
    return true;
}
int main()
{
    int n,k,seyz = 0;
    cin>>n;
    if (n>2){
        if(n%2==0) //by goldbach conjecture
            seyz=2;
        else if(is_prime(n))
            seyz=1;
        else{
            if(is_prime(n-2))
                seyz=2;
            else
                seyz=3;
        }
    }
    else
        seyz=1;
    /*
    else{
        if(is_prime(n)){
            //cout<<n<<endl;
            n-=n;
            seyz+=1;
        }
        else{
            k=n-1;
            while(is_prime(k)==false){k-=1;}
            //cout<<k<<"\n";
            n-=k;
            seyz+=1;
        }
    }
    */
    cout<<seyz;
    return 0;
}
