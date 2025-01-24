#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;

void solve(int turn, int cursor) {
	vector<int> target = arr[turn];
	
	
}
int main() {
	int n;
	cin >> n;
	
	int sel[9] = {};
	
	for (int i = 0;i < n; i++) {
		vector<int> a;
		for (int j = 0; j < 9; j++) {
			int in;
			cin >> in;
			a.push_back(in);
		}
		
		arr.push_back(a);
	}
	for (int i = 1;i < 9; i++) {
		if (i >= 4) sel[i] = i + 1;	
		sel[i] = i;
	
		
	}
	
	sel[0] = 1;
	queue<int> q;
	
	int maxscore = 0;
	do {
		
		int temp = sel[3]; // 4번타자
		sel[0] = temp;
		sel[3] = 0; 
//		
//		for (int i =0 ; i < 9; i++) {
//			cout << sel[i] << " ";
//		}
//		cout << endl;
		
		int score =0;
		int cursor = 0;
		
		for (auto &turn : arr) {
			int outcnt = 0;
			
			while(outcnt <= 2) {
				int batter = sel[cursor];
				int hit = turn[batter];
				
				if (hit == 0) outcnt++;
				if (hit == 1) {
					q.emplace(1);
				}
				if (hit == 2) {
					q.emplace(1);
					q.emplace(0);
				}
				if (hit == 3) {
					q.emplace(1);
					q.emplace(0);
					q.emplace(0);
				}
				if (hit == 4) {
					while(!q.empty()) {
						int c = q.front(); q.pop();
						if (c == 1) score++;
					}
					score++;
				}
				while(q.size() > 3) {
					int c = q.front(); q.pop();
					if (c == 1) score++;
				}
				cursor = (cursor + 1) % 9;
			}
			while(!q.empty()) q.pop();
		}
		
		maxscore = max(maxscore, score);
		sel[3] = sel[0];
		
	} while(next_permutation(sel + 1, sel + 9));
	cout << maxscore << endl;
}