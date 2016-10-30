#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define M map<string,int>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    M s;
    s.insert({"a",100});
    if(!s.find("a")==s.end())
    	cout<<s.find('a')-s.begin();
    return 0;
}

