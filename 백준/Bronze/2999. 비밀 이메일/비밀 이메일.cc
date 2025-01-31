#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	int r, c;
	for (int i = 1; i <= sqrt(s.length()); i++) {
		if (s.length() % i == 0) {
			r = i;
		}
	}
	c = s.length() / r;
	
	char arr[101][101];
	int idx = 0;
	for (int i = 0; i < c ;i++) {
		for (int j = 0; j < r; j++) {
			arr[j][i] = s[idx];
			idx++;
		}
	}
	
	for (int i= 0; i < r; i++) {
		for (int j= 0;j < c; j++) {
			cout << arr[i][j];
		}
	}
}