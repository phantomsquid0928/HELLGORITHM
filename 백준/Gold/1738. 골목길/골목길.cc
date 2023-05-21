#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> nodes[104];
vector<array<int, 3>> nodes2;
vector<int> ans;
int hist[104];

int dist[103];
int visited[103] = {};

void dfs(int node) {
	//cout << "dfs : " << node;
	for (auto t : nodes[node]) {
		if (!visited[t.first]) {
			visited[t.first] = 1;
			dfs(t.first);
		}
	}
}
void bfs(int node) {
	queue<int> q;
	q.push(node);
	while (!q.empty()) {
		int target = q.front();
		q.pop();
		for (auto t : nodes[target]) {
			if (!visited[t.first]) {
				visited[t.first] = 1;
				q.push(t.first);
			}
		}
	}
}

void print_ans(int t) {
	if (t == 1) {
		cout << t << " ";
		return;
	}
	print_ans(hist[t]);
	cout << t << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i< m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		//nodes[a].push_back({b, c});
		nodes[b].push_back({a, c});
		nodes2.push_back({a, b, -c});
	}
	//memset(dist, 0x1f1f, sizeof(dist));
	for (int i = 1; i <= n ;i++) {
		dist[i] = 1000000000;
	}
	dist[1] = 0;
	
	hist[1] = 1;
	visited[n] = 1;
	int iscycle = 0;
	bfs(n);
	for (int i = 1; i <= n; i++) {
		for (auto t : nodes2) {
			int temp = t[0];
			int next = t[1];
			int val = t[2];
			if (dist[temp] != 1000000000 && dist[next] > dist[temp] + val) {
				dist[next] = dist[temp] + val;
				hist[next] = temp;
				if (i == n && visited[temp] == 1) {
					iscycle = 1;
				}
			}
		}
	}
	
	if (iscycle == 1) {
		cout << -1 << '\n';
		return 0;
	}
	int last = n;
	int j = n;
//	for (auto t : cycle) {
//		memset(visited, 0, sizeof(visited));
//
//		dfs(t[0]);
////		for (int i = 1; i <= n; i++) {
////			cout << visited[i] << " ";
////		}
//		if (visited[1] == 1 && visited[n] == 1) {
//			cout << -1;
//			return 0;
//		}
//	}
	
//	for (int j = 1; j <= n; j++) {
//		for (int k = 1; k <= n; k++) {
//			cout << hist[j][k] << " ";
//		}
//		cout << endl;
//	}
//	ans.push_back(last);
	
	print_ans(n);
//	cout << endl;
//	cout << dist[n] << endl;
}