#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> dots;

int visited[15];

int mincost = 0x3f3f3f3f;
int n = -1;
void dfs(int cur, int cost, int cnt) {
	if (cnt == n) {
		array<int, 2> final = dots[1];
		array<int, 2> curpoint = dots[cur];
		
		int finalcost = abs(curpoint[0] - final[0]) + abs(curpoint[1] - final[1]);
		
		mincost = min(mincost, cost + finalcost);
		return;
	}
	if (cost > mincost) return;
	array<int, 2> curpoint = dots[cur];
	
	for (int i = 2; i < n + 2; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		
		array<int, 2> nextpoint = dots[i];
		int ncost = abs(curpoint[0] - nextpoint[0]) + abs(curpoint[1] - nextpoint[1]);
		
		dfs(i, cost + ncost, cnt + 1);
		visited[i] = 0;
	}
}
int main() {
	int t;
	
	cin >> t;
	
	for (int tt = 1; tt <= t; tt++) {
		cin >> n;
		
		mincost = 0x3f3f3f3f;
		memset(visited, 0, sizeof(visited));
		dots.clear();
		
		for (int i = 0; i < n + 2; i++ ){
			int a, b;
			cin >> a >> b;
			dots.push_back({a, b});
		}
		
		dfs(0, 0, 0);
		
		cout << "#" << tt << " " << mincost << endl;
	}
}