#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;
 
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }

    while (i <= mid) {
        aux[k++] = arr[i++];
    }

    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
 
    return inversionCount;
}
 

int mergeSort(int arr[], int aux[], int low, int high)
{
    if (high <= low) {
        return 0;
    }

    int mid = (low + ((high - low) >> 1));
    int inversionCount = 0;
 
    inversionCount += mergeSort(arr, aux, low, mid);

    inversionCount += mergeSort(arr, aux, mid + 1, high);
 
    inversionCount += merge(arr, aux, low, mid, high);
 
    return inversionCount;
}


int main() {

    int n;
	cout << "Enter the number of test cases:" << endl;
	cin >> n;

    n++;
    while(n--) {
        int num;
        cout << "Enter the size of the vector:" << endl;
	    cin >> num;

        int array[num];
        for(int i = 0; i < num; i++) {
            cin >> array[i];
        }
        int aux[num];
        for (int i = 0; i < num; i++) {
            aux[i] = array[i];
        }

        int count = mergeSort(array, aux, 0, num - 1);
        cout << "count " << count << endl;

    }

    return 0;
}