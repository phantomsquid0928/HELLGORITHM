#include <bits/stdc++.h>

using namespace std;

vector<array<int, 3>> ops;
int sel[10] = {};

int arr[101][101] = {};
int hist[101][101] = {};

void calc(array<int, 3> ops) {
	int r = ops[0];
	int c = ops[1];
	int s = ops[2];
	
	
	vector<vector<int>> targets = {};
	vector<vector<int>> res = vector<vector<int>>(2 * s + 1, vector<int>(2 * s + 1, 0));
	
	for (int i = r-s; i <= r + s; i++) {
		vector<int> target;
		for (int j = c-s; j <= c + s; j++) {
			target.push_back(arr[i][j]);
		}
		targets.push_back(target);
	}
	
	res[s][s] = targets[s][s];
	
	for (int size = 1; size <= s; size++) {
		int start = s - size;
		int end = s + size;
		
		for (int i = end - 1; i >= start; i--) {
			res[start][i + 1] = targets[start][i];
		}
		
		for (int i = 0; i <= end - 1; i++) {
			res[i][start] = targets[i + 1][start];
		}
		
		for (int i = start; i <= end - 1; i++) {
			res[end][i] = targets[end][i + 1];
		}
		
		for (int i = end - 1; i >= start; i--) {
			res[i + 1][end] = targets[i][end];
		} 
	}
	
	for (int i = r - s; i <= r + s; i ++) {
		for (int j = c - s; j <= c + s; j++) {
//			cout << res[i - r + s][j - c + s] << " ";
			arr[i][j] = res[i - r + s][j - c + s];
		}
//		cout << endl;
	}
}
int main() {
	int n,m, k;
	cin >> n >> m >> k;
	
	for (int i =0 ; i< n; i++) {
		for (int j  =0;j < m; j++) {
			cin >> arr[i][j];
			hist[i][j] = arr[i][j];
		}
	}
	
	
	for (int i = 0;i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		ops.push_back({r - 1, c - 1, s});
		
//		calc({r - 1, c - 1, s});
//		for (int i = 0;i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				cout << arr[i][j] << " ";
//			}
//			cout << endl;
//		}
		sel[i] = i + 1;
	}
	int minres = 5000;
	do {
		for (int i =0 ; i< n; i++) {
			for (int j = 0;j < m; j++) {
				arr[i][j] = hist[i][j];
			}
		}
//		cout << "sel";
		for (int i = 0; i < k; i++) {
			
			calc(ops[sel[i] - 1]);
			
//			cout << "res" << endl;
//			for (int i = 0; i < n; i++) {
//				for (int j =0 ;j < m; j++) {
//					cout<< arr[i][j] << " ";
//				}
//				cout << endl;
//			}
		}
//		cout << endl;
		
		int res = 5000;
		for (int i = 0;i < n;i++) {
			int sum = 0;
			for (int j =0 ; j < m; j++) {
				sum += arr[i][j];
			}
			res = min(res, sum);
		}
		minres = min(res, minres);
	} while (next_permutation(sel, sel + k));

	
	
	cout << minres;
}