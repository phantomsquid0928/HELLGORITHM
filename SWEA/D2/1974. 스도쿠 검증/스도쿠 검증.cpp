#include <bits/stdc++.h>

using namespace std;

int arr[9][9];
int main() {
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; tt++) {
		for (int i = 0;i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> arr[i][j];
			}
		}
		
		bool valid = true;
		
		for (int i = 0;i < 9; i++) {
			int check = 0;
			int check2 = 0;
			for (int j = 0;j < 9; j++) {
				check |= (1 << arr[i][j]);
				check2 |= (1 << arr[j][i]);
			}
//			cout << i << " ro " << check << endl;
//			cout << i << " col " << check2 << endl;
			if (check != 1022) valid = false;
			if (check2 != 1022) valid = false;
		}
		
		for (int i = 0; i < 3; i++) {
			for (int j= 0;j < 3; j++) {
				int sum = 0;
				for (int t = 3 * i; t < 3 * i + 3; t++) {
					for (int k = 3 * j; k < 3 * j + 3; k++) {
						if (t > 9 || k > 9) continue;
						sum |= (1 << arr[t][k]);
					}
				}
//				cout << i << " " << j << " " << sum << endl;
				if (sum != 1022) valid = false;
			}
		}
		
		if (valid) cout << "#" << tt << " " << 1 << endl;
		else cout << "#" << tt << " " << 0 << endl;
	}
}