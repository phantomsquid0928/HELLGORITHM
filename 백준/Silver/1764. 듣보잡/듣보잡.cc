#include <bits/stdc++.h>

using namespace std;

set<string> s;
vector<string> res;
int main() {
	int n, m;
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i =0 ;i < n; i++)  {
		string temp;
		cin >> temp;
		s.insert(temp);
	}
	for (int i = 0; i< m; i++) {
		string temp;
		cin >> temp;
		if (s.count(temp)) {
			res.push_back(temp);
		}
	}
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (auto i : res) {
		cout << i << '\n';
	}
}