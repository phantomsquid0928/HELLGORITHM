#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr[101];
int match[10000];
int visited[10000];

bool dfs(int i) {
	if (visited[i]) return false;
	visited[i] = true;
	for (auto t : arr[i]) {
		if (match[t] == -1 || dfs(match[t])) {
			match[t] = i;
			return true;
		}
	}
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
	}
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) ++ans;
	}
	cout << ans;
}