#include <bits/stdc++.h>

using namespace std;

int indeg[32001];
vector<int> graph[32001];

queue<int> q;
int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0;i <m; i++) {
		int a, b;
		cin >> a >> b;
		
		indeg[b]++;
		graph[a].push_back(b);
	}
	
	for (int i = 1; i <= n; i++) {
		if (indeg[i]==0) q.push(i);
	}
	
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		
		cout << cur << " ";
		
		for (int n : graph[cur]) {
			indeg[n]--;
			if (indeg[n] == 0) q.push(n);
		}
	}
}