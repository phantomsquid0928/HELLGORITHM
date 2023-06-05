#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[1000];
int arr[1000][1000] = {};
int adj[1000][1000] = {};
vector<int> visited;



int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){ 
		char a, b;
		int c;
		cin >> a >> b >> c;
		int x = a - 'A';
		int y = b - 'A';
		arr[x][y] += c;
		arr[y][x] += c;
		graph[x].push_back({y, c});
		graph[y].push_back({x, c});
		//arr2.push_back({a, b, c});
		
	}
//	for (int i = 0; i < 1000; i++) {
//		if (!arr[i].empty()) {
//			for (auto t : arr[i]) {
//				cout << i << ":" << t.first << " - " << t.second << endl;
//			}
//		}
//	}
	int res = 0;
	int start = 0;
	int end = 'Z' - 'A';
	
	while(1) {
		queue<int> q;
		vector<int> visited(1000, -1);
	
		q.push(start);
		while(!q.empty()) {
			int t = q.front();
			q.pop();
			
			for (auto i : graph[t]) {
				int y = i.first;
				if (arr[t][y] - adj[t][y] > 0 && visited[y] == -1) {
					visited[y] = t;
					q.push(y);
					if (y == end) break;
				}
			}
		}
		if (visited[end] == -1) break; //modi
		
		int flow = 10000000;
		for (int i = end; i != start; i = visited[i]) flow = min(flow, arr[visited[i]][i] - adj[visited[i]][i]);
		for (int i = end; i != start; i = visited[i]) {
			adj[visited[i]][i] += flow;
			adj[i][visited[i]] -= flow;
		}
		
		res += flow;
		
		//hist sail to get min flow of path
		//add minflow cap on ans
		//adjust arr
	}
	cout << res;
	
}