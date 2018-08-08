#include <iostream>
#include <deque> 
using namespace std;

struct Maxx
{
    int maxVal, maxpos;
    struct Maxx computeMax(int arr[], int startPos, int count)
    {
        int i {startPos};
        struct Maxx ret {arr[startPos], startPos};
        for (; i < startPos + count; i++)
            if (arr[i] > ret.maxVal)
            {
                ret.maxVal = arr[i];
                ret.maxpos = i;
            }
        return ret;
    }
} ;

void printKMax(int arr[], int n, int k){
	//Write your code here.

    
    int j, max_of_arr;
    Maxx element;
    element = element.computeMax(arr, 0, k);
    cout << element.maxVal << " ";

    for (j = 1; j < n - k + 1; j++)
    {
        element.maxpos--; // shifting to the right decrement position of maximum in array
        if (element.maxpos < j) // no maximum is out of range, so update it
            element = element.computeMax(arr, j, k);
        if (arr[j + k - 1] > element.maxVal) // shifting to the right sets the maximum to the newest element of the array
        {
            element = {arr[j + k - 1], j + k - 1};

        }
        cout << element.maxVal << " ";
    }
    
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}