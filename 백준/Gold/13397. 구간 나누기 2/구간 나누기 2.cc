#include<bits/stdc++.h>

using namespace std;

int a[5001];
int solve(int mid, int m, int n) {
	int minv = a[0];
	int maxv = a[0];
	int cnt = 1;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > maxv) maxv = a[i];
		if (a[i] < minv) minv = a[i];
		if (maxv - minv <= mid) continue;
		if (maxv - minv > mid) {
			cnt++;
			minv = a[i];
			maxv = a[i];
		}
	}
//	cout << cnt << endl;
	if (cnt <= m) {
		return -2;
	}
	if (cnt > m) {
		return -1;
	}
}
int main() {
	int n, m;
	cin >> n >>m;
	
	int maxc = 0;
	for (int i =0 ;i < n; i++) {
		cin >> a[i];
		if(a[i] >maxc) maxc = a[i];
	}
	//a[n] = 100000;
	int start= -1;
	int end = 10000;
	for (int i = 0; i < 50; i++) {
		int mid = start + end >> 1;
		int res = solve(mid, m, n);
		if (res == -1) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	cout << end;
}