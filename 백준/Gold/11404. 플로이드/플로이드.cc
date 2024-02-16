#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> arr[101];
priority_queue<pair<int, int>> pq;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m; i++) {
		int a, b, c;
		cin>>a>>b>>c;
		arr[a].push_back({b, c});
	}
	
	for (int i = 1; i<= n; i++){
		int dist[101] = {};

		memset(dist, 0x3f, sizeof(dist));
		dist[i] = 0;
		pq.push({0, i});
		
		while(!pq.empty()) {
			int t = pq.top().second;
			int d = -pq.top().first;
			pq.pop();
			for (auto a : arr[t]) {
				if (dist[a.first] <= d + a.second) continue;
				dist[a.first] = d + a.second;
				pq.push({-dist[a.first], a.first});
			}
		}
		for (int j = 1; j <= n; j++) {
			if (dist[j] == 1061109567) {
				cout<< 0 << " ";
			} 
			else {
				cout << dist[j]<<" ";
			}
		}
		cout << endl;
	}
}