#include <iostream>
#include <vector>
#include <string>
#include <sstream>
typedef long long LL;
using namespace std;

void augment(string& periodic_number, LL L) {
    switch(periodic_number[L]) {
        case '0': periodic_number[L] = '1';
                    break;
        case '1': periodic_number[L] = '2';
                    break;
        case '2': periodic_number[L] = '3';
                    break;
        case '3': periodic_number[L] = '4';
                    break;
        case '4': periodic_number[L] = '5';
                    break;
        case '5': periodic_number[L] = '6';
                    break;
        case '6': periodic_number[L] = '7';
                    break;
        case '7': periodic_number[L] = '8';
                    break;
        case '8': periodic_number[L] = '9';
                    break;
        case '9': periodic_number[L] = '0';
                    break;
    }
}
bool ckecked(string& periodic_number, string& number) {
    for (auto i = 0; i < number.length(); i += periodic_number.length()) {
        for (auto j = 0; j < periodic_number.length(); j++) {
            if (periodic_number[j] < number[i + j]) {
                // cout << "found difference between positions " << j+1 << " in periodic and " << 1+i+j << " in number;"
                //      << periodic_number[j] << " -- " << number[i+j] << endl;
                return false;
            }
            else if (periodic_number[j] > number[i + j])
                return true;
        }
    }
    if (periodic_number[periodic_number.length() - 1] == number[number.length() - 1])
        return false;
    return true;
}

int main()
{
    LL L;
    cin >> L;
    string number;
    cin >> number;
    LL times = number.length() / L;
    if (number.length() % L != 0) {
        stringstream ss;
        ss << '1';
        for (auto i = 1; i < L; ++i)
            ss << '0';
        string periodic_number = ss.str();
        for (auto i = 0; i <= times; ++i)
            cout << periodic_number;
    }
    else {
        string periodic_number = number.substr(0, L);
        if (!ckecked(periodic_number, number))
        for (auto i = L - 1; i > -1; --i) {
            augment(periodic_number, i);
            if (periodic_number[i] != '0')
                break;
        }
        if (periodic_number[0] == '0') {
            periodic_number[0] = '1';
            cout << periodic_number;
        }
        for (auto i = 0; i < times; ++i)   
            cout << periodic_number;
    }
    cout << endl;
    return 0;
}