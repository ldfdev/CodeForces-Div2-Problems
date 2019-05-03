#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> num(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    char digits[10];
    for(int i = 1; i <= 9; i++)
        cin >> digits[i];
    bool contiguous = false, end_of_contiguous = false;
    for(int i = 1; i <= n; i++)
    {
        // cout << "comparing digit " << num[i] << " against " << digits[num[i]] << endl;
        if ((end_of_contiguous==false) && (digits[num[i] - '0'] > num[i]))
        {
            cout << digits[num[i] - '0'];
            contiguous = true;
        }
        else if (digits[num[i] - '0'] == num[i])
        {
            cout << num[i];
        }
        else
        {
            cout << num[i];
            if (contiguous == true)
                end_of_contiguous = true;
        }
    }
    cout << endl;
    // cout << "number read: ";
    // for(auto& v : num)
    //     cout << v;
    // cout << endl;
    // cout << "digits read: ";
    // for(auto& v : digits)
    //     cout << v;
    return 0;
}