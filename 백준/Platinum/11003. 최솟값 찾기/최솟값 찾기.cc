#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

priority_queue<array<int, 2>> pq;

int main() {
	int n, l;
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> l;
	
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		
		pq.push({-in, i});
		
		while (1){
			auto a = pq.top();
			if (i - a[1] <l) break;
			pq.pop();
		}
		
		auto a = pq.top();
		cout << -a[0] << " ";
	}
	
	
}