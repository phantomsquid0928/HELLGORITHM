#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> tree[10001];
int visited[10001];

int res = 0;
int dfs(int a ){
//	cout <<a<<endl;
	if (visited[a]) {
		return 0;
	}
	visited[a] = 1;
	if (tree[a].size() == 1) {
//		cout << "r" << endl;
		return 0;
	}
	int maxcost = 0;
	int sumcost = 0;
	vector<int> costs;
	for(auto i : tree[a]) {
		if(visited[i.first]) continue;
		int cost = dfs(i.first) + i.second;
		maxcost = max(cost, maxcost);
//		sumcost += cost;
		costs.push_back(-cost);
		
	}
	sort(costs.begin(), costs.end());
	if (costs.size() == 1) {
		sumcost = -costs[0];
	}
	else {
		sumcost = -costs[0] -costs[1];
	}
//	cout << a << "]" << maxcost << ":" << sumcost << endl;
	res = max(res, sumcost);
//	res = max(res, maxcost);
	return maxcost;
	
	
}
int main() {
	int n;
	cin >> n;
	for (int i= 1; i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({b,c});
		tree[b].push_back({a, c});
	}
	tree[0].push_back({1, 0});
	tree[1].push_back({0, 0});
	dfs(1);
	cout << res << endl;
}