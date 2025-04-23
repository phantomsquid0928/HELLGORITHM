#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr[1001];
int match[1001];
int visited[1001];

bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = 1;
	for (auto i : arr[a]) {
		if (match[i] == -1 || dfs(match[i])) {
			match[i] = a;
			return true;
		}
	}
	return false;
}
int matching() {
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int i= 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));

		if (dfs(i)) ++ans;
		
	}
	return ans;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		for (int j = 1; j <= t; j++) {
			int k;
			cin >> k;
			arr[i].push_back(k);
		}
	}
	cout << matching() << endl;

}