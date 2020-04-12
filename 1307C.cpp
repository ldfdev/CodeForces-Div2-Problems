#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
    string letters;
    cin >> letters;

    ll occurences_pair = 0;
    map<string, ll> pairs;
    map<char, ll> already_found;

    for (char ch : letters) {
        if (already_found.empty()) {
            already_found.insert(make_pair(ch, 1));
        }
        else {
            for (auto l : already_found) {
                char let;
                ll num;
                tie(let, num) = l;
                string new_pair {let, ch};
                if (pairs.count(new_pair))
                    pairs[new_pair] += num;
                else
                    pairs[new_pair] = num;
            }
            already_found[ch] += 1;
        }

    }

    for (auto p : pairs)
        if(p.second > occurences_pair)
            occurences_pair = p.second;



    
    // check if it is better to take just 1 character llo account (i.e. the maximal substring has length 1)
    vector<ll> every_letter(26, 0);
    for (char ch : letters)
        every_letter[ch - 'a'] += 1;
    
    ll occurences_singleton = 0;
    for (ll ch : every_letter)
        if (occurences_singleton < ch)
            occurences_singleton = ch;
    
    cout << max(occurences_singleton, occurences_pair) << endl;
    return 0;
}