#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<array<int, 2>> graph[1001];
priority_queue<array<ll, 2>> pq;
int  main() {
	int n, m;
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m;
	
	
	for (int i =0 ;i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		graph[a].push_back({b, c});
	}
	
	int start, end;
	cin >> start >> end;
	
	ll dist[1001];
	
	memset(dist, 0x3f, sizeof(dist));
	
	dist[start] = 0;
	
	
	
	pq.push({0, start});
	
	while(!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		
		int node = cur[1];
		int cost = -cur[0];
		
		if (dist[node] < cost) continue;
		for (auto &next : graph[node]) {
			int nnode = next[0];
			int ncost = next[1];
			
			if (dist[nnode] > dist[node] + ncost) {
				dist[nnode] = dist[node] + (ll)ncost;
				pq.push({-dist[nnode], nnode});
			}
		}
	}
	
	cout << dist[end] << endl;
}