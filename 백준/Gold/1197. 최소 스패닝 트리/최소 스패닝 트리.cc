#include <bits/stdc++.h>

using namespace std;

int unionfind[1000000];
int _rank[1000000];

int find(int a) {
	if (a == unionfind[a]) return a;
	return unionfind[a] = find(unionfind[a]);
}
void _union(int a, int b) {
	a = find(a);
	b = find(b);
	
	if (a == b) return;
	if (_rank[a] < _rank[b]) {
		unionfind[a] = b;
	}
	else if (_rank[a] > _rank[b]) {
		unionfind[b] = a;
	}
	else {
		unionfind[b] = a;
		_rank[a]++;
	}
}

vector<array<int, 2>> graph[100001];
int main() {
	int v, e;
	
	cin >> v >> e;
	
	for (int i= 0;i < e; i++) {
		int a, b, c;
		
		cin >> a >> b >>c;
		
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	
	vector<array<int, 3>> arr;
	
	for (int i = 1; i <= v; i++) {
		unionfind[i] = i;
		for (auto j : graph[i]) {
			arr.push_back({j[1], i, j[0]});
		}
	}
	
	sort(arr.begin(), arr.end());
	
//	for (auto &a : arr) {
//		cout << a[0] << endl;
//	}
	vector<array<int, 3>> res;
	for (auto &a : arr) {
		if (find(a[1]) == find(a[2])) continue;
		res.push_back(a);
		_union(a[1], a[2]);
	}
	int sum = 0;
	for (auto &r : res) {
		sum += r[0];
//		cout << r[1] << " " << r[2] << " " << r[0] << endl;
	}
	cout << sum << endl;
}