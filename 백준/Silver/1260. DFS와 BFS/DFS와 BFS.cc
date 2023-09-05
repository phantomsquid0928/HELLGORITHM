#include<bits/stdc++.h>

using namespace std;

vector<int> arr[10001];

int visited[10001];
int n, m, v;
int first = 1;
queue<int> q;
void dfs(int a) {
	cout << a << " ";
	visited[a] =1;
	
	for (auto i : arr[a]) {
		if (visited[i]) continue;
		dfs(i);
	}
}
int main(){
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++){ 
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i < n + 1; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	dfs(v);
	cout << endl;
	memset(visited, 0, sizeof(visited));
	q.push(v);
	while(!q.empty()) {
		int t = q.front();
		
		q.pop();
		if (visited[t]) continue;
		visited[t] = 1;
		cout << t << " ";
		for (auto i : arr[t]) {
			q.push(i);
		}
	}
}