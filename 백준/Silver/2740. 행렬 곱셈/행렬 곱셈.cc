#include <bits/stdc++.h>

using namespace std;

int a[101][101];
int b[101][101];
int res[101][101];
int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0;i  < n; i++) {
		for (int j =0 ;j < m; j++) {
			cin>> a[i][j];
		}
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j  = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < m; l++) {
				res[i][j] += a[i][l] * b[l][j];
			}
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}