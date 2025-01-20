#include <bits/stdc++.h>

using namespace std;

int arr[50][50];

int main (){
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int n;
		cin >> n;
		
		memset(arr, 0, sizeof arr);
		for (int i = 0; i< n ;i++) {
			string s;
			cin >> s;
			for (int j= 0; j < n;j++) {
				arr[i][j] = s[j] - 48;
			}
		}
		
		int sum = 0;
		for (int i = 0;i < n; i++) {
			int a = abs(n / 2 - i);
			int b = n - a;
			
			for (int j = a; j < b; j++) {
				sum += arr[i][j];
			}
		}
		
		cout << "#" << test << " " << sum << endl;
		
	}
}