#include <bits/stdc++.h>

using namespace std;

int notprime[1000010];
int main() {
	int m, n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	
	notprime[1] = -1;
	for (int i = 2; i * i <= n; i++) {
		if (!notprime[i]) {
			for (int j = i * i; j <= n; j+= i) {
				notprime[j] = i;
			}
		}
	}
	
	for (int i = m; i<=n; i++) {
		if (!notprime[i])
			cout << i << '\n'; 
	}
//	int tmp = 300;
//	while(notprime[tmp]) {
//		cout << notprime[tmp] << " ";
//		tmp /= notprime[tmp];
//	}
//	cout << tmp << endl;
}