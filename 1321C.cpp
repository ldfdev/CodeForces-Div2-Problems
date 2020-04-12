#include <bits/stdc++.h>

using namespace std;

inline int max_index(string& s) {
    int mx = -1;
    if (s.size() < 2)
        return mx;
    for(int i = 0; i < s.size(); ++i) {
        int mxtmp = -1;
        if (i == 0) {
            if (s[i] == 1 + s[i + 1])
                mxtmp = i;
        }
        else {
            if (s[i] == 1 + s[i - 1])
                mxtmp = i;
            if ((i < s.size() - 1) && (s[i] == 1 + s[i + 1]))
                mxtmp = i;
        }
        if (mxtmp != -1) {
            if (mx == -1)
                mx = mxtmp;
            else if (s[mx] < s[mxtmp])
                mx = mxtmp;
        }
    }
    return mx;
}

int main()
{
    int s, removed = 0;
    cin >> s;
    string letters;
    cin >> letters;
    while(true) {
        int mx = max_index(letters);
        // cout << letters << " " << mx << " ";
        if (mx == -1)
            break;
        if (mx == 0) {
            letters = letters.substr(mx + 1, letters.size() - 1 - mx);
        } else if (mx < letters.size() - 1) {
            letters = letters.substr(0, mx) + letters.substr(mx + 1, letters.size() - 1 - mx);
        } else 
            letters = letters.substr(0, mx);
        ++removed;
    }
    cout << removed << endl;
    return 0;
}