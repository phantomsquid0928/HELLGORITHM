#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	queue<int> arr;
	for (int i = 1;i <= n; i++) {
		arr.emplace(i);
	}
	
	while(arr.size() > 1) {
		arr.pop();
		int t = arr.front(); arr.pop();
		arr.emplace(t);
	}
	cout << arr.front() << endl;
}