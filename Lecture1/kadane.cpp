#include <iostream>

using namespace std;


int max_subarray(int array[], int length) {
    int best_sum = array[0];
    int current_sum = array[0];

    for(int i = 1; i < length; i++) {
        current_sum = max(array[i], current_sum + array[i]);
        best_sum = max(best_sum, current_sum);
    }

    return best_sum;
}

int main() {

    int n;
	cout << "Enter the number of items:" << endl;
	cin >> n;

    int numArray[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >>  numArray[i];
    }

    cout << max_subarray(numArray, n);


    return 0;
}