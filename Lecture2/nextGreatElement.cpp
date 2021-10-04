#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findGreatElem(int array[], int length) {

    deque<int> s;

    s.push_front(array[0]);

    for(int i = 1; i < length; i++) {
        if(s.empty()) {
            s.push_front(array[i]);
            continue;
        }

        while(s.empty() == false && s.front() < array[i]) {
            cout << " " << array[i]; 
            s.pop_front(); 
        }

        s.push_front(array[i]); 
    }

    while (s.empty() == false) { 
        cout << " " << -1; 
        s.pop_front(); 
    } 

}


int main() {
    
    int n;
	cout << "Enter the number of items:" << endl;
	cin >> n;

    int numArray[n];
    for (int i = 0; i < n; i++) {
       cin >> numArray[i];
    }

    findGreatElem(numArray, n);

    return 0;
}