#include <bits/stdc++.h>
typedef unsigned long long ll;

const ll upperBound = sqrt(1e7 + 1), sz = 5e5;
ll primesCnt = 1;
ll primeDivs[upperBound], primes[upperBound], d1[sz], d2[sz];

void getPrimeDivisors() {
    primes[0] = 2;
    for (ll i = 4; i <= upperBound; i += 2)
        primeDivs[i] = -1; //mark them as non prime
    for (ll i = 3; i <= upperBound; i += 2) {
        if (primeDivs[i] == -1)
            continue;
        // if i is not marked then i is a prime
        primes[primesCnt++] = i;
        for (ll j = i * i; j <= upperBound; j += i)
            primeDivs[j] = -1;
    }
}

ll getFirstDiv(ll arr) {
    for (ll idx = 0; idx < primesCnt; idx++) {
        ll div = primes[idx];
        if ((div * div) > arr) return 0;
        if (arr % div == 0)    return div;
    }
    return 0;
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    getPrimeDivisors();
    ll n, i, arr;
    std::cin >> n;
    
    for(i = 1; i <= n; i++) {
        std::cin >> arr;
        ll firstDiv = getFirstDiv(arr);
        
        ll copy_of_arr = arr;
        if (firstDiv != 0) {
            while(copy_of_arr % firstDiv == 0) {
                copy_of_arr /= firstDiv;
            }
        }
        if ((firstDiv == 0) || (copy_of_arr == 1)) {
            d1[i] = 0;
            d2[i] = 0;
        }
        else {
            d1[i] = copy_of_arr;
            d2[i] = arr / copy_of_arr;
        }
    }
    for(i = 1; i <= n; i++) {
        if (d1[i] > 0)
            std::cout << d1[i] << " ";
        else
            std::cout << "-1 ";
    }
    std::cout << "\n";
    for(i = 1; i <= n; i++) {
        if (d2[i] > 0)
            std::cout << d2[i] << " ";
        else
            std::cout << "-1 ";
    }
    return 0;
}