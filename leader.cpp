#include <iostream>
using namespace std;


void findLeader(int array[], int length) {
    int cur_max = 0;
    cout << "Leaders are: \n";

    for(int i = length-1; i >= 0 ; i--)
    {
        if(array[i] > cur_max)
        {
          cout << array[i] <<" ";
          cur_max = array[i];
        }
    } 

}

int main() {

    int n;
    cout << "Enter the number of items:" << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
       cin >> arr[i];
    }

    findLeader(arr, n);

    return 0;
}