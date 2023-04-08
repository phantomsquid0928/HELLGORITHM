#include <bits/stdc++.h>

using namespace std;

int a[10003];
int n, m;
int solve(long long mid) {
	long long sum = 0;
	int chk = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < mid) {
			sum += a[i];
		}
		else {
			chk = 1;
			sum += mid;	
		}
	}
	if (chk == 0) return -1;
	if (sum > m) return -1;
	return 1;
}
int main() {
	cin >> n;
	for (int i =0 ; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	long long start = 1;
	long long end = 10000000000000l;
	for (int i = 0; i < 100; i++) {
		long long mid = start + end >> 1;
		int res = solve(mid);
		if (res == -1) {
			end = mid;
		}
		else {
			start = mid;
		}
	}
	cout << start;
}