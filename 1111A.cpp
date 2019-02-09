// A. Superhero Transformation

#include <bits/stdc++.h>

using namespace std;


int main()
{
    string vowels {"aeiou"};
    string s, t, answer {"Yes"};
    cin >> s >> t;
    if (s.length() < t.length())
        answer="No";
    else
        for (auto i = 0; i < s.length(); i++) {
            if (i == t.length()) {
                answer = "No";
                break;
            }
            if ((vowels.find(s[i]) != string::npos) and (vowels.find(t[i]) == string::npos)) {
                answer = "No";
                break;
            }
            if ((vowels.find(t[i]) != string::npos) and (vowels.find(s[i]) == string::npos)) {
                answer = "No";
                break;
            }
        }
    cout << answer << endl;
}