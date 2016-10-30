#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_balanced(string expression) {
	int l=expression.length();
	stack<string> S1,S2,S3;
	for(int i=0;i<l;++i){
		if(!expression.compare(i,1,"("))
			S1.push("(");
		else if(!expression.compare(i,1,")"))
			if(S1.empty())
				return false;
			else
				S1.pop();
		else if(checker && !expression.compare(i,1,"["))
			S2.push("[");
		else if(!expression.compare(i,1,"]"))
			if(S2.empty())
				return false;
			else
				S2.pop();
		else if(!expression.compare(i,1,"{"))
			S3.push("{");
		else if(!expression.compare(i,1,"}"))
			if(S3.empty())
				return false;
			else
				S3.pop();
		}
	if(S1.empty() && S2.empty() && S3.empty())
		return true;
	else
		return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

