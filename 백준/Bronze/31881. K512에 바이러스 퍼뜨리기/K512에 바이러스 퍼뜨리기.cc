#include <bits/stdc++.h>

using namespace std;

int arr[200000];
int main() {
	int n, q;
	int busted = 0;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 0;i < q; i++) {
		int mod;
		cin >> mod;
		if (mod == 1) {
			int x;
			cin >> x;
			int old = arr[x - 1];
			arr[x - 1] = 1;
			if (old != arr[x - 1]) busted++;
		}
		else if (mod == 2){ 
			int x;
			cin >> x;
			int old = arr[x - 1];
			arr[x - 1] = 0;
			if (old != arr[x - 1]) busted--;
		}
		else {
			cout << n - busted << '\n';
			//rint
		}
	}
}