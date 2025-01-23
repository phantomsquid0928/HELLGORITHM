#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> dots;
int graph[11][11] = {};
int sel[11] = {};

int main() {
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++){
		int n;
		cin >> n;
		
//		cout << n << endl;
		
		memset(sel, 0, sizeof(sel));
		memset(graph, 0, sizeof(graph));
		dots.clear();
		
		for (int i = 0; i < n; i++) {
			sel[i] = i + 2;
		}
		//company always 0 my home always n + 1;
		
		for (int i = 0;i < n + 2; i++) {
			int a, b;
			cin >> a >> b;
			
			dots.push_back({a, b});
		}
		
		int mincost = 0x3f3f3f3f;
		do {
			int cost = 0;
			int now = 0;
			int fin = 1;
			
//			cout << now << " ";
			for (int i = 0;i < n; i++) {
//				cout << sel[i] << " ";
				auto cur = dots[now];
				auto next = dots[sel[i]];
				
				int dist = abs(cur[0] - next[0]) + abs(cur[1] - next[1]);
				cost += dist;
				
				now = sel[i];
			}
//			cout << fin << endl;
			
			auto cur = dots[now];
			auto next = dots[fin];
			
			int dist = abs(cur[0] - next[0]) + abs(cur[1] - next[1]);
			cost += dist;
			
			mincost = min(cost, mincost);
		} while (next_permutation(sel, sel + n));
		
		cout << "#" << tt << " " << mincost << endl;
	}
}