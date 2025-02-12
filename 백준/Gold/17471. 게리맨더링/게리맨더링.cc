#include <bits/stdc++.h>

using namespace std;

vector<int> graph[11];
int pop[11];

bool test(int start, int * group, int n, int mod) {
	queue<int> q;
	
	q.push(start);
	
	int visited[11] = {};
	visited[start] = 1;
	
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		
		for (auto &n : graph[cur]) {
			if (group[n] != group[cur]) continue;
			if (visited[n]) continue;
			visited[n] = 1;
			q.push(n);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (mod && group[i] && !visited[i]) return false;
		if (!mod && !group[i] && !visited[i]) return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	
	int arr[11] = {};
	
	for (int i = 0; i < n; i++){ 
		cin >> pop[i + 1];
	}
	for (int i = 0; i< n; i++) {
		int t;
		cin >> t;
		
		arr[i] = i + 1;
		for (int j = 0; j < t; j++) {
			int in;
			cin >> in;
			
			graph[i + 1].push_back(in);
			graph[in].push_back(i + 1);
		}
	}
	
	queue<int> q;
	
	int groupnums[11];
	int minres = 0x3f3f3f3f;
	for (int i = 1; i <= n / 2; i++) {
		int sel[11] = {};
		for (int j = 0; j < i; j++) {
			sel[j] = 1;
		}
		
		
		do {
			memset(groupnums, 0, sizeof(groupnums));
			int startg1 = -1;
			int startg2 = -1;
			
			int num = 0;
			int num2 = 0;
			for (int i = 0; i < n; i++) {
				if (sel[i]) {
//					cout << arr[i] << " ";
					groupnums[arr[i]] = 1;
					startg1 = arr[i];
					num += pop[arr[i]];
				}
				else {
					startg2 = arr[i];
					num2 += pop[arr[i]];
				}
			}
			
//			for (int i = 1; i<=n ;i++) {
//				cout << groupnums[i];
//			}
//			cout << endl;
//			cout << endl;
			
			//test linkage...
			
			bool res = test(startg1, groupnums, n, 1);
			bool res2 = test(startg2, groupnums, n, 0);
			
			if (res && res2) {
				minres = min(minres, abs(num - num2));
			}
			
//			cout << endl;
		}while(prev_permutation(sel, sel + n));
	}
	
	if (minres == 0x3f3f3f3f) cout << -1 << endl;
	else cout << minres << endl;
}