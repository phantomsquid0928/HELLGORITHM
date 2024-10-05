#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> tree[100001];

int visited[100001];

int width = 0;

int furthest = -1;
void dfs(int v, int cost) {
	visited[v] = 1;
	//cout << v << " " << cost << endl;
	for (auto &i : tree[v]) {
		if (visited[i[0]]) continue;
		furthest = (width < cost + i[1] ? i[0] : furthest);
		width = max(width, cost + i[1]);
		
		dfs(i[0], cost + i[1]);
	}
}
int main() {
	int v;
	cin >> v;
	int start;
	for (int i =0 ;i < v; i++) {
		int j;
		int nv;
		int dist;
		cin >> j;
		if (i == 0) start = j;
		
		while(1) {
			cin >> nv;
			if (nv == -1) break;
			cin >>dist;
			tree[j].push_back({nv, dist});
		}
		
		
	}
	
	dfs(start, 0);
	//cout << furthest << endl;
	memset(visited, 0, sizeof(visited));
	dfs(furthest, 0);
	cout << width << endl;
	
	
	
	
}