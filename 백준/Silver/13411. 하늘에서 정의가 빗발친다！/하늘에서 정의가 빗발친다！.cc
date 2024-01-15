#include <bits/stdc++.h>

using namespace std;

int arr[100001];

vector<pair<double, int>> info;
int main() {
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n ; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		double sec = sqrt(x * x + y * y) / v;
		info.push_back({sec, i + 1});
	}
	sort(info.begin(), info.end());
	for (auto i : info) {
		cout << i.second << '\n';
	}
	
}