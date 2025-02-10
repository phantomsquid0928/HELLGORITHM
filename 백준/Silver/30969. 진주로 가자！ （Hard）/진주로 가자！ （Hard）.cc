#include <bits/stdc++.h>
#define ll long long

using namespace std;

int cnts[1001];

int main() {
	int n;
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	int res = 0;
	
	int lim = -1;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ll in;
		cin >> in;
		if (in > 1000) {
			res++;
			continue;
		}
		if (!s.compare("jinju")) {
			lim = in;
			continue;
		}
		else {
			cnts[in]++;
		}
	}
	
	for (int i = lim + 1; i <= 1000; i++) {
		res += cnts[i];
	}
	
	cout << lim << endl << res << endl;
}