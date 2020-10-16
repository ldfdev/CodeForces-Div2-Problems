#include <bits/stdc++.h>

typedef long long ll;

const int sz = 2e5;
int seq[sz];


int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int tests, n;
    std::string s;
    std::cin >> tests;
    while(tests--) {
        std::cin >> n >> s;
        int min_s = 1;
        // first element belongs to first seq
        
        seq[0] = min_s;
        std::stack<int> stacks[2];
        stacks[0] = std::stack<int>();
        stacks[1] = std::stack<int>();
        stacks[s[0] - '0'].push(1);
        for (ll i = 1; i < n; i++) {
            int ch = 0;
            if ('0' == s[i])
                ch = 1;
            // std::cout << "first element is " << s[i] << ".Searching for match " << ch << std::endl;
            if (stacks[ch].empty()) {
                min_s += 1;
                stacks[s[i] - '0'].push(min_s);
                seq[i] = min_s;
            }
            else {
                seq[i] = stacks[ch].top();
                stacks[ch].pop();
                if (ch == 1)
                    stacks[0].push(seq[i]);
                else
                    stacks[1].push(seq[i]);
            }
        }

        std::cout << min_s << "\n";
        for (ll i = 0; i < n; i++) {
            std::cout << seq[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}