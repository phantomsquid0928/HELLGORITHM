#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt = 100004;
	if (n == 4) {
		cout << -1 << endl;
		return 0;
	}
	int t = n / 3;
	
	for(int i = 0; i< t + 1; i++) {
		if ((n - 3 * i) % 5 == 0) {
			cnt = min(cnt, (n - 3 * i) / 5 + i);
		}
	}
	if(cnt == 100004) {
		cout << -1 << endl;
	}
	else {
		cout << cnt << endl;
	}
}