#include <bits/stdc++.h>

char arr[1001];
int i;

int count_value(int start_index, char value) {
    int pos = start_index, cnt = 0;
    while(true) {
        if (arr[pos] == '\0')
            return cnt;
        if (arr[pos] == value)
            ++cnt;
        ++pos;
    }
    return cnt;
}

int compute_all_costs(char shouldStartWith) {
    std::vector<int> intermediateCosts;
    int index, firstCost, index2;
    for (index = 0; index < i; ++index) {
        firstCost = 0;
        for (index2 = 0; index2 < index; ++index2)
            if (arr[index2] != shouldStartWith)
                ++firstCost;
        firstCost += count_value(index, shouldStartWith);
        intermediateCosts.push_back(firstCost);
    }
    return (*std::min_element(intermediateCosts.begin(), intermediateCosts.end()));
}

int main ()
{
    int tests;
    char c;
    scanf("%d", &tests); scanf("%c", &c);
    while(tests--) {
        i = 0;
        scanf("%c", &c);
        while (c != '\n') {
            arr[i++] = c;
            scanf("%c", &c);
        }
        arr[i] = '\0';
        // compute all the costs of having 0-1s, 
        // next compute all the costs of having 1-0s, 11-0s, 111-0s ...
        int cost01, cost10, cost;
        cost01 = compute_all_costs('0');
        cost10 = compute_all_costs('1');
        cost = std::min(cost01, cost10);
        
        printf("%d\n", cost);
    }
    return 0;
}