#include <bits/stdc++.h>

using namespace std;

int main() {
	int arr[100][100] = {};
	
	int n;
	cin >> n;
	
	for (int t = 0;t < n; t++) {
		int a, b;
		cin >> a >> b;
		
		for (int i = a; i < a + 10; i++) {
			for (int j = b; j < b + 10; j++) {
				arr[i][j] = 1;
			}
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < 100;i++){ 
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) cnt++;
		}
	}
	cout <<  cnt << endl;
}