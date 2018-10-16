#include <iostream>

using namespace std;

// struct List {

//     List (int n) : index (1) {
//         list = new int[n]; list[0] = 1;
//         dictionary = new bool[n + 1];
//         for (int i = 1; i <= n; i++)
//             dictionary[i] = false;

//     }

//     virtual ~List () {
//         delete[] list, dictionary;
//     }

//     void add_to_list (int value, int parentRouter) {
//         if (dictionary[parentRouter] == false)
//         {   
//             list [index ++] = value;
//             dictionary[parentRouter] = true;
//         }
//     }
//     void showResult() {
//         // cout << "showResult index = " << index << endl;
//         for (int i = 0; i < index; i++)
//             cout << list[i] << " ";
//     }

// int index;
// int *list;
// bool *dictionary;

// };

int main ()
{
    // int n, parentRouter;
    // cin >> n;
    // List list(n);
    // for (int i = 2; i <= n; i++)
    // {   
    //     // cout << "Loop processing " << parentRouter << endl;
    //     cin >> parentRouter;
    //     list.add_to_list(i, parentRouter);
    // }
    // cout << endl;
    // list.showResult();
    
    // second attempt

    int n, index = 0;
    cin >> n;
    int arr[n + 1], rever[n+1];
    for (int i = 2; i <= n; i++)
        cin >> arr[i];
    arr[1] = 1;

    int temp = n;
    while (temp != 1){
        rever[index++] = temp;
        temp = arr[temp];
    }
    index--;
    cout << 1 << " ";
    for (int i = index; i >=0; i--)
        cout << rever[i] << " ";
        

    
    return 0;
}