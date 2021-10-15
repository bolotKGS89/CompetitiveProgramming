#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void countKsum(int a[], int k, int n) {
   	map<int, int> mp;
	mp.clear();   
	
	int sum=0,l=1,r=1,_max=0;
	int L=1,R=1;
	while(r<=n)
	{
		while(sum <= k && r <= n)
		{
			if(mp[a[r]]==0) sum++;
			mp[a[r]]++;
			r++;
		}
		if(sum>k) r--,mp[a[r]]--,sum--;
		if(_max<r-l)
		{
			_max=r-l;
			L=l,R=r-1;
		}
		while(sum>=k&&l<=n)
		{
			mp[a[l]]--;
			if(mp[a[l]]==0) sum--;
			l++;
		}
	}
	cout << L+1 << " " << R+1;

}

int main() {

    int n;
	cout << "Enter the number elements of array:" << endl;
	cin >> n;

    int k;
    cout << "Enter k parameter:" << endl;
    cin >> k;

    int array[n+1];
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    countKsum(array, k, n);

    return 0;
}