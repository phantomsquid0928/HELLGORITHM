#include <bits/stdc++.h>

using namespace std;

int n, m;
int visited[9];
int arr[9];

void back(int r) {
	ios::sync_with_stdio(0);
	cout.tie(0);
	if (r == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		arr[r] = i;
	
		back(r + 1);
		
		visited[i] = 0;
	}
}
int main() {
	cin >> n >> m;
	back(0);
}