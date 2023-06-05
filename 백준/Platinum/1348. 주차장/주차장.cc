#include <bits/stdc++.h>

using namespace std;

int r, c;
int arr[100][100];
int visited[101][100];
bool visited1d[1000];
int M = -1;
int match[1000];

vector<array<int, 3>> starts;
vector<array<int, 3>> endpoints;
vector<array<int, 2>> reaches[101];

void setdist(array<int, 3> tt, int b) {
	queue<array<int, 3>> q;
	memset(visited, 0, sizeof(visited)); 
	q.push({tt[0], tt[1], 0});
	
	int dt[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	while(!q.empty()) {
		array<int, 3> t = q.front(); q.pop();
		int x = t[0];
		int y = t[1];
		int dist = t[2];
		if (arr[x][y] >= 0) {
			reaches[b].push_back({arr[x][y], dist});
		}
		//cout << "x : " << t[0] << "y : " << t[1] << "dist: " << t[2] << endl;
		dist++;
		for (int k = 0; k < 4; k++) {
			int dx = x + dt[k][0];
			int dy = y + dt[k][1];
			if (dx < 0 || dx >= r || dy < 0 || dy >= c) {
				continue;
			}
			if (arr[dx][dy] == -2) continue;
			if (visited[dx][dy] == 1) continue;
			
		
			visited[dx][dy] = 1;
			q.push({dx, dy, dist});
			
		}
	}
}
bool dfs(int a, int mid) {
	if (visited1d[a]) {
		//cout << "fd";
		return false;
	}
	visited1d[a] = true;
	for (auto t : reaches[a]) {
		if (mid >= t[1] && match[t[0]] == -1) {
			match[t[0]] = a;
			//cout << "tt";
			return true;
		}
	}
	for (auto t : reaches[a]) {
		if (mid >= t[1] && dfs(match[t[0]], mid)) {
			match[t[0]] = a;
			//cout << "tt";
			return true;
		}
	}
	//tt = 0;
	//cout << "ss";
	return false;
}
int matching(int mid) {
	memset(match, -1, sizeof(match));
	int ans = 0;
	for (int i = 0; i < starts.size(); i++) {
		memset(visited1d, 0, sizeof(visited1d));
		if (dfs(i, mid)) ++ans;
	}
	return ans;
//	printf("%d", ans); 
}
int main() {
	cin >> r >> c;
	int t = 0;
	for (int i = 0; i< r; i++) {
		for (int j = 0; j < c; j++) {
			char c;
			cin >> c;
			if (c == 'C') {
				arr[i][j] = -3	;
				starts.push_back({i, j, 3});
			}
			if (c == 'P') {
				arr[i][j] = t;
				endpoints.push_back({i, j, t});
				t++;
			}
			if (c == 'X') {
				arr[i][j] = -2;
			}
			if (c == '.') {
				arr[i][j] = -1;
			}
		}
	}

//	for (int i = 0; i< r; i++) {
//		for (int j = 0; j < c; j++) {
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
	int ff = 0;
	for (auto t : starts) {
		setdist(t, ff);
		ff++;
	}
	
	int start = 0;
	int end = 10000000;
	for (int i = 0; i< 50; i++) {
		int mid = start + end >> 1;
		if (matching(mid) < starts.size()) start = mid;
		else end = mid;
	}
	if (matching(end) == starts.size()) cout << end;
	else cout << "-1";
//	for (int i = 0;i < ff; i++) {
//		cout << match[i] << " ";
//	}
//	for (int i =0 ; i< ff; i++) {
//		for (auto t : reaches[i]) {
//			
//			cout << "x : " << t[0] << "y : " << t[1] << "parknum: " << t[2] << "dist : " << t[3] << endl;
//		}
//	}
	
}