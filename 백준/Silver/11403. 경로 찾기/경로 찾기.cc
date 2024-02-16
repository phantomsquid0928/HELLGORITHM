#include <bits/stdc++.h>

using namespace std;

int arr[101][101];
//vector<int> a[101];
int main() {
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i <n ;i++ ){
		for (int j =0 ;j < n;j++) {
			cin >> arr[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i =0;i < n; i++) {
			for (int j = 0;j < n; j++) {
				arr[i][j] += arr[i][k] * arr[k][j];
			}
		}

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 0) {
				cout << 0 << " ";
			}
			else {
				cout << 1 << " ";
			}
		}
		cout << endl;
	}
	
	
}