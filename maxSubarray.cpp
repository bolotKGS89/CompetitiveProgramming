#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void print_max(int a[], int n, int k) {

    int max_upto[n];

    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            max_upto[s.top()] = i - 1;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        max_upto[s.top()] = n - 1;
        s.pop();
    }
    int j = 0;
    for (int i = 0; i <= n - k; i++) {

        while (j < i || max_upto[j] < i + k - 1)
            j++;
        cout << a[j] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
	cout << "Enter the size of array: " << endl;
	cin >> n;

    cout << "Enter the size of subarray: " << endl;
    cin >> k;

    int num_array[n - 1];
    for (int i = 0; i < n - 1; i++) {
       cin >> num_array[i];
    }

    print_max(num_array, sizeof(num_array) / sizeof(int), k);

    return 0;
}