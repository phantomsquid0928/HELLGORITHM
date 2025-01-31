#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int arr[101];
	
	for (int i = 0; i< n; i++) {
		cin >> arr[i];
	}
	
	int t;
	cin >> t;
	
	for (int i = 0; i< t; i++) {
		int x, idx;
		cin >> x >> idx;
		
		if (x == 1) {
			for (int i = 0; i < n;i++) {
				if ((i + 1) % idx == 0) {
					arr[i] = arr[i] ^ 1;
				}
			}
		}
		else {
			int start = idx - 1;
			int end = idx - 1;
			while(1) {
				if (start < 0 || end >= n) break;
				if (arr[start] != arr[end]) break;
				
				start = start - 1;
				end = end + 1;
			}
			for (int i = start + 1; i <= end - 1; i++) {
				arr[i] ^= 1;
			}
		}
	}
	
	for (int i = 0;i < n; i++) {
		if (i % 20 == 0 && i != 0) cout << endl;
		cout << arr[i] << " ";
		
	}
}