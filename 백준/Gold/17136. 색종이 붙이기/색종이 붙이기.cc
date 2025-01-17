#include <bits/stdc++.h>

using namespace std;

int cnts[5] = {5, 5, 5, 5, 5};
int arr[11][11];
int covered[11][11] = {};

int ones = 0;
int minres = 1000;

//void solve(int t, int used) {
//	if (ones == 0) {
//		
//		minres = min(minres, used);
//		return;
//	}
//	if (used > minres) return;
////	cout << t << endl;
//	int x = t / 10;	
//	int y = t % 10;
//	while(1) {
//		x = t / 10;
//		y = t % 10;
//		if (t >= 100 || (arr[x][y] == 1 && covered[x][y] == 0)) break;
//		t++;
//	}
//	if (t >= 100) return;
//	
////	cout << t << endl;
//	
//	for (int size = 4; size >= 0; size--) {
//		bool valid = true;
//		
//		if (x + size >= 10 || y + size >= 10) {
//			continue;
//		}
//		for (int i = x; i <= x + size; i++) {
//			for (int j = y; j <= y + size; j++) {
//				if (arr[i][j] == 0) valid = false;
//			}
//		}
//		if (valid && cnts[size] >= 1) {
////			cout << "selected" << t << "size" << size << endl;
//			ones -= (size + 1) * (size + 1);
//			cnts[size]--;
//			for (int i = x; i <= x + size; i++) {
//				for (int j = y; j <= y + size; j++) {
//					covered[i][j] = 1;
//				}
//			}
//			solve(t + size + 1, used + 1);
//			for (int i = x; i <= x + size; i++) {
//				for (int j = y; j <= y + size; j++) {
//					covered[i][j] = 0;
//				}
//			}
//			cnts[size]++;
//			ones += (size + 1) * (size + 1);
//		}
//	}
//}
//int minres = 1000;

void solve(int t, int used) {
	int x = t / 10;
	int y = t % 10;
	if (minres < used) return;
	while(1) {
		x = t / 10;
		y = t % 10;
		if (t >= 100) {
			if (ones != 0) return;
			minres = min(minres, used);
			return;
		}
		if (arr[x][y] == 1 && covered[x][y] == 0) break;
		t++;
	}
	
	
	
//	cout << t << endl;
	
	for (int size = 4; size >= 0; size--) {
		if (x + size >= 10 || y + size >= 10) continue;
		if (cnts[size] < 1) continue;
		
		bool valid = true;
		for (int i = x; i <= x + size; i++) {
			for (int j = y; j <= y + size; j++) {
				if (arr[i][j] == 0 || covered[i][j]) valid = false;
			}
		}
		if (!valid) continue;
		
		for (int i = x; i <= x + size; i++) {
			for (int j = y; j <= y + size; j++) {
				covered[i][j] = 1;
			}
		}
		ones -= (size + 1) * (size + 1);
		cnts[size]--;
		solve(t + 1, used + 1);
		for (int i = x; i <= x + size; i++) {
			for (int j = y; j <= y + size; j++) {
				covered[i][j] = 0;
			}
		}
		cnts[size]++;
		ones += (size + 1) * (size + 1);
		
	}
}
int main() {
	
	
	for (int i =0 ;i <10; i++) {
		for (int j =0 ; j< 10; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) ones++;
		}
	}
	
	solve(0, 0);
	
	if (minres == 1000) cout << -1 << endl;
	else cout << minres << endl;
}
