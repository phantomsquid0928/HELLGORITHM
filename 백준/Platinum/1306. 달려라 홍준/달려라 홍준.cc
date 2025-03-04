#include <bits/stdc++.h>
#define ll long long

using namespace std;

int arr[1000001];

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i =0 ;i < n; i++) {
		cin >> arr[i];
	}
	int light = 0;
	
	priority_queue<array<int, 2>> pq;
	for (int i = 0; i < 2 * m - 1; i++) {
		pq.push({arr[i], i});
	}
	vector<ll> res;
//	res.push_back(pq.top()[0]);
	for(int i = m - 1; i <= n - m; i++) {
		while(!pq.empty()) {
			auto cur = pq.top(); 
			if (cur[1] < i - m + 1) {
				pq.pop();
				continue;
			}
			break;
		}
//		cout << pq.size() << endl;
		pq.push({arr[i + m - 1], i + m - 1});
		res.push_back(pq.top()[0]);
	}
	for (auto i: res) {
		cout << i << " ";
	}
	cout << endl;
}