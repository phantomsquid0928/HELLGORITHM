#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<array<int, 2>> arr[20001];
int dist[20001];
int main() {
	int v, e;
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> v >> e;
	int start;
	cin >> start;
	
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		arr[a].push_back({b, c});

	}
	
	memset(dist, 0x3f, sizeof(dist));
	dist[start] = 0;
	
	auto comp = [](array<int, 2> &a, array<int, 2>&b) {
		return a[0] > b[0];
	};
	priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(comp)> pq(comp);
	pq.push({0, start});
	
	while(!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		
		int now = cur[1];
		int cost = cur[0];
		
		if (dist[now] < cost) continue;
		
		for (auto &i : arr[now]) {
			int n = i[0];
			int ncost = i[1];
			if (dist[n] <= dist[now] + ncost) continue;
			dist[n] = dist[now] + ncost;
			
			pq.push({dist[n], n});
		}
	}
	
	for (int i = 1; i <= v; i++ ){
		if (dist[i] == 0x3f3f3f3f) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	
	
}