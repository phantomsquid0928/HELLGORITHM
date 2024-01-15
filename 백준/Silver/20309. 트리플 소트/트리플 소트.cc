#include <bits/stdc++.h>

using namespace std;

int arr[300001];
int main() {
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){ 
		cin>>arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
//			cout << i << endl;
			if (arr[i] % 2 != 1) {
				cout << "NO" << endl;
				return 0;
			}
		}
		else {
//			cout << i  << "ff" << endl;
			if (arr[i] % 2 != 0) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	
}