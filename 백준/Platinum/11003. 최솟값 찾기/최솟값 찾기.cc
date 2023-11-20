#include <bits/stdc++.h>

using namespace std;

priority_queue<array<int, 2>> pq; //value, burntime
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, l;
	cin >> n >> l;
	for (int i =0 ;i < n; i++) {
		int t;
		cin >> t;
		pq.push({-t, i});
		int val = -pq.top()[0];
		int burn = pq.top()[1];
		while(i - burn >= l) {
			pq.pop();
			val = -pq.top()[0];
			burn = pq.top()[1];
		}
		cout << val << " ";
	}
}