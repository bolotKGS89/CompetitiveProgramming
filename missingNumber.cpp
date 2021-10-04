#include <iostream>

using namespace std;



int getMissingNumber(int array[], int length)
{
    int sum_all_num = (length * (length + 1)) / 2;
    int sum_user_num = 0;

    for (int i = 0; i < length - 1; i++)
    {
        sum_user_num += array[i];
    }

    int num = sum_all_num - sum_user_num;

    return num;
}

int main() {
    int n;
	cout << "Enter the number of items:" << endl;
	cin >> n;

    int numArray[n - 1];
    for (int i = 0; i < n - 1; i++) {
       cin >> numArray[i];
    }

    cout << "Missing number is : " << getMissingNumber(numArray, n) << endl;
    
    return 0;
}