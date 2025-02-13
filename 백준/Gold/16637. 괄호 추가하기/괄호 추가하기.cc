#include <bits/stdc++.h>

using namespace std;

int sel[20];
vector<char> ops;
vector<int> nums;


int calc() {
	vector<int> cp(nums.begin(), nums.end());
	for (int i = 0;i < ops.size(); i++) {
		if (!sel[i]) continue;
		char op = ops[i];
		int res;
		if (op == '-') res = cp[i] - cp[i + 1];
		if (op == '*') res = cp[i] * cp[i + 1];
		if (op == '+') res = cp[i] + cp[i + 1];
		cp[i] = res;
//		cp[i + 1] = 0;
	}
//	for (auto &i : cp) {
//		cout << i << " ";
//	}
//	cout << endl;
	int res = cp[0];
	for (int i = 0; i < ops.size(); i++) {
		if (sel[i]) {
//			if (res == 0)
			continue;
		}
//		int target = cp[i + 1];
	
		char op = ops[i];
		if (op == '-') res -= cp[i + 1];
		if (op == '*') res *= cp[i + 1];
		if (op == '+') res += cp[i + 1];
//		cout << "applied> " << cp[i + 1] << "res : " << res << endl;
	}
	
//	cout << "final" << res << endl;
	
	return res;
}
int maxres = INT_MIN;
void dfs(int a, int n, int k) {
	if (n == k) {
//		for (int i = 0; i < ops.size(); i++) {
//			cout << sel[i] << " ";
//		}
//		cout << endl;
		maxres = max(maxres, calc());
		
		return;
	}
	for (int i = a; i < ops.size(); i++) {
		if (sel[i]) continue;
		if (i > 0 && sel[i - 1]) continue;
		sel[i] = 1;
		dfs(i, n, k + 1);
		sel[i] = 0;
	}
}

int main() {
	int n;
	cin>>n;
	
	for (int i =  0; i< n; i++ ){
		char c;
		cin >> c;
		if (c == '+' || c == '*' || c == '-') {
			ops.push_back(c);
		}
		else {
			nums.push_back(c - '0');
		}
	}
	if (ops.size() == 0) {
		cout << nums[0] << endl;
		return 0;
	}
	for (int i = 1; i <= ops.size(); i++) {
		dfs(0, i, 0);
	} 
	cout << maxres << endl;
}