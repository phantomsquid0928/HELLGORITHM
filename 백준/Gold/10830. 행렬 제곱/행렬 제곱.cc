#include <bits/stdc++.h>
#define ll long long

using namespace std;


vector<vector<int>> matmul(vector<vector<int>> a, vector<vector<int>> b) {
	int n = a.size();
	int m = a[0].size();
	int l = b[0].size();
	vector<vector<int>> res(n, vector<int>(l, 0));
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < l; j++) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % 1000;
			}
		}
	}
	
	return res;
}

unordered_map<ll, vector<vector<int>>> mem;

vector<vector<int>> solve(vector<vector<int>> a, ll b) {
//	cout << ": " <<  b << endl;
	if (mem.count(b)) {
		return mem[b];
	}
	if (b == 1) {
		auto res = a;
		
		return a;
	}
	if (b == 2) {
		int n = a.size();
		
		auto res = matmul(a, a);
		
		mem[b] = res;
		return res;
	}
	else {
		auto c = solve(a, (ll)(floor(b / 2)));
		auto d = solve(a, (ll)(b - floor(b/ 2)));
		
		auto res = matmul(c, d);
		
		mem[b] = res;
		
		return res;
	}
}
int main() {
	int n;
	ll b;
	
	cin >> n >>b;
	vector<vector<int>> arr;
	for (int i =0 ;i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int in;
			cin >> in;
			temp.emplace_back(in);
		}
		arr.emplace_back(temp);
	}
	
	vector<vector<int>> res = solve(arr, b);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] % 1000 << " ";
		}
		cout << endl;
	}
}