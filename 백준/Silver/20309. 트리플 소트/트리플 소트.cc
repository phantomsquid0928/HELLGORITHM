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
	for (int i = 1; i < n -1; i++) {
		for (int j = n - 2; j >= i; j--) {
			if (arr[j - 1] > arr[j + 1]) {
				int t = arr[j - 1];
				arr[j - 1] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
		if (arr[i - 1] != i) {
			cout << "NO" << endl;
			
			return 0;
		}
	}
	if (arr[n - 1] == n && arr[n - 2] == n - 1) {
		cout << "YES" << endl;	
	}
	else {
		cout << "NO" << endl;
	}

	
}