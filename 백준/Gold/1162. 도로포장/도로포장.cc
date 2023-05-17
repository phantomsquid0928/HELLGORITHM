#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<pair<int, int>> nodes[10004];
long long dist[31][10003];

int main() {
	cin >> n >> m >> k;
	
	for (int i = 0; i< m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({b, c});
		nodes[b].push_back({a, c});
	}
	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 100000000000000000ll;
		}
		dist[i][1] = 0;
	}
	priority_queue<array<long long, 3>> q;
	q.push({dist[0][1], 1, 0});
	while(!q.empty()) {
		int kk = q.top()[2];
		int temp = q.top()[1];
		long long tempdist = -q.top()[0];
		q.pop();
		
		if (dist[kk][temp] < tempdist) continue;
		for (auto t : nodes[temp]) {
			int next = t.first;
			int val = t.second;
			if (dist[kk + 1][next] > dist[kk][temp] && kk <= k) {
				dist[kk + 1][next] = dist[kk][temp];
				
				q.push({-dist[kk + 1][next], next, kk + 1});
			}
			if (dist[kk][next] > dist[kk][temp] + val) {
				dist[kk][next] = dist[kk][temp] + val;
					
				q.push({-dist[kk][next], next, kk});
			}
		}
	}
//	for (int i = 0; i <= k; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dist[i][j] << " ";
//		}
//		cout << endl;
//	}
	long long res = 1000000000000ll;
	for (int kk = 0; kk <= k; kk++) {
		res = min(res, dist[kk][n]);
	}
	cout << res << endl;
}