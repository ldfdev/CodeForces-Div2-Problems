#include <bits/stdc++.h>
#define long long int;

int arr[(int)(1e5 + 1)];
int n, x;

int find_length() {
    int S = 0, remove_from_head = 0, remove_from_tail = 0, i;
    
    for (i = 0; i < n; i++) {
        std::cin >> arr[i];
        S += arr[i];
    }
    
    if (S % x != 0)
        return n;
    
    while (arr[remove_from_head] % x == 0) {
        ++remove_from_head;
        if (remove_from_head == n)
            break;
    }
    if (remove_from_head == n)
        return -1;

    while (arr[n - 1 - remove_from_tail] % x == 0)
        ++remove_from_tail;
    
    if (remove_from_head < remove_from_tail)
        return (n - remove_from_head - 1);
    return (n - remove_from_tail - 1);
}

int main()
{
    int tests;
    std::cin >> tests;
    while(tests--) {
        std::cin >> n >> x;
        std::cout << find_length() << "\n";
    }
    return 0;
}