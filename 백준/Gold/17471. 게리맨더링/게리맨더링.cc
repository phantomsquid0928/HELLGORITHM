#include <bits/stdc++.h>

using namespace std;

int pop[11];
int sel[11];

vector<int> graph[11];

bool check(int n, int start) {
	int color = sel[start];
	
	int visited[11] = {};
	
	queue<int> q;
	q.push(start);
	
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		
		if (visited[cur]) continue;
		visited[cur] = 1;
		
		
		for (int n : graph[cur]) {
			if (visited[n]) continue;
			if (sel[n] != color) continue;
			q.push(n);
		}
	}
	
//	cout << " visited" << endl;
//	for (int i = 1; i <= n ;i++) {
//		cout << visited[i] << " ";
//	}
//	cout << endl;
	
	bool valid = true;
	for (int i = 1; i <= n; i++) {
		if ((sel[i] == color) && !visited[i]) valid = false;
	}
	if (!valid) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	
	for (int i =1  ;i <= n; i++) {
		cin >> pop[i];
	}
	
	for (int i = 1; i <= n; i++ ){
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			int u;
			cin >> u;
			graph[i].push_back(u);
			graph[u].push_back(i);
		}
	}
	
	int minres = 100000000;
	bool valid_exists = false;
	for (int i = 1; i <= (n >> 1); i++) {
		memset(sel, 0, sizeof(sel));
		for (int j = 1 ; j <= i; j++) {
			sel[j] = 1;
		}
		do {
			bool valid = false;
			//con check
			
//			for (int k = 0; k <= n; k++) {
//				cout << sel[k] << " ";
//			}
//			cout << endl;
			valid = check(n, 1);
			
//			cout << "vlid : "<<    valid << endl;
			int other = -1;
			
			for (int k = 1; k <= n; k++) {
				if (sel[1] != sel[k]) {
					other = k;
					break;
				}
			}
			
			valid &= check(n, other);
			
			//calc diff
			if (!valid) continue;
			valid_exists = true;
			int asum = 0;
			int bsum = 0;
			
			for (int k = 1; k <= n; k++) {
				if (sel[k]) asum += pop[k];
				else bsum += pop[k];
			}
			minres = min(minres, abs(asum - bsum));
		} while(prev_permutation(sel + 1, sel + n + 1));
	}
	
	if (valid_exists) cout << minres << endl;
	else cout << -1 << endl;
	//11C1 ~ 11C5 = ??
	
	
}