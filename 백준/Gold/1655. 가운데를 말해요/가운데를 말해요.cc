#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int> smal;
priority_queue<int> big;
int query[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0;i < n; i++) {
		cin >> query[i];
	}
	for (int i = 0; i< n; i++) {
		if (i == 0){ 
			cout << query[i] << "\n";
			smal.push(query[i]);
			continue;
		}
		int temp = smal.top();
		if (temp > query[i]) {
			smal.push(query[i]);
		}
		else {
			big.push(-query[i]);
		}
		int left = smal.size();
		int right = big.size();
		
		if (left < right){
			int temp = -big.top();
			big.pop();
			smal.push(temp);
		}
		else if (left > right + 1) {
			int temp = smal.top();
			smal.pop();
			big.push(-temp);
		}
		cout << smal.top() << "\n";
	}
	
}