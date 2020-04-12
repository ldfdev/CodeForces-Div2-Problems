#include <iostream>
#include <vector>
#include <string>
using namespace std;



auto main() -> int
{
    int T;
    cin >> T;
    for (auto t = 0; t < T; ++t) {
        vector<pair<char,int>> s;
        long long n, pipeUnitCost, pillarUnitCost;
        cin >> n >> pipeUnitCost >> pillarUnitCost;
        vector<bool> marked(n + 1, false);
        s.push_back({'0', 1});
        marked[0] = true;
        for (auto i = 1; i <= n; ++i) {
            char ch;
            cin >> ch;
            if (ch == '1') {
                int many = 0;
                if (marked[i - 1] == false)
                    ++many;
                if (marked[i] == false)
                    ++many;
                if (s.back().first == ch)
                    s.back().second += many;
                else
                    s.push_back({ch, many});
                marked[i - 1] = marked[i] = true;
            }
            else if (marked[i - 1] == false) {
                if (s.back().first == ch)
                    s.back().second += 1;
                else
                    s.push_back({ch, 1});
                marked[i - 1] = true;
            }
        }
        if (s.back().first == '0')
            s.back().second += 1;
        else
            s.push_back({'0', 1}); // for last pillar
        // for (auto item : s) {
        //     int height = 1;
        //     if (item.first == '1')
        //         height = 2;
        //     for (auto kk = 0; kk < item.second; ++kk)
        //         cout << "Pillar H" << height << endl;
        // }

        long long cost = n * (pipeUnitCost + pillarUnitCost) + pillarUnitCost;
        bool isMarked = false; // if pillar of height 2 are used when there is no crossroads, set variable true
        for (auto i = 0; i < s.size(); ++i) {
            if(s[i].first == '0') {
                if (isMarked == false) {
                    // determine if 1 follow
                    long long oldCost = cost;
                    bool oneFollow = true;
                    if (i == s.size() - 1)
                        oneFollow = false;
                    
                    if (oneFollow)
                        cost += pipeUnitCost;
                    if (i > 0) // previously 1 has been encountered, so pillar is lowered
                        cost += pipeUnitCost;
                    // cout << "0             cost = " << cost - oldCost << endl;
                }
                else {
                    // cout << "0 [is marked] cost = N/A" << endl;
                    isMarked = false; /*cost has been registered while visiting previous height-2 pillars*/}
            }
            else {
                // determine if 1 follow
                long long oldCost = cost;
                cost += pillarUnitCost * s[i].second;

                bool oneFollow = false;
                if (i + 2 <= s.size() - 1)
                    oneFollow = true;
                
                if (oneFollow) {
                    /*cost if all pilars are of height 2*/
                    auto deltaCost1 = pillarUnitCost * s[i + 1].second;
                    /*cost if pilars are lowered over regions of height 1*/
                    auto deltaCost2 = 2 * pipeUnitCost;
                    if (deltaCost1 < deltaCost2)
                    {
                        isMarked = true;
                        cost += deltaCost1;
                    }
                }
                // string of = "";
                // if (oneFollow)
                //     of = "oneFollow";
                // cout << "1 cost " << of << " = " << cost - oldCost << endl;
            }
        }
        cout << cost << endl;
    }
    return 0;
}