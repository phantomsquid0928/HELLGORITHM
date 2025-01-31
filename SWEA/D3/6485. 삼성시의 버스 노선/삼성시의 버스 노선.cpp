#include <bits/stdc++.h>

using namespace std;

int arr[501];
vector<array<int, 2>> infos;
int main() {
	int t;
	cin >> t;
	
	for (int tt=  1; tt <= t; tt++) {
		int n;
		cin >> n;
		infos.clear();
		memset(arr, 0, sizeof(arr));
		
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			infos.push_back({a, b});
		}
		int p; cin >> p;
		for (int i = 0; i < p; i++) {
			cin >> arr[i];
		}
		
		cout << "#" << tt << " ";
		for (int i = 0; i < p; i++) {
			int cnt = 0;
			for (auto &info : infos) {
				if (info[0] <= arr[i] && arr[i] <= info[1]) {
					cnt++;
				}
			}
			cout << cnt << " ";
		}
		cout << endl;
	}
}