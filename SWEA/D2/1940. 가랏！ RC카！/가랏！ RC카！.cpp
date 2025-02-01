#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int tt=  1; tt <= t; tt++) {
		int n;
		cin >> n;
		int vel = 0;
		int res = 0;
		
		for (int i = 0;i <n ;i++) {
			int a, b;
			cin >> a;
			if (a == 0) {
				res += vel;
			}
			if (a == 1) {
				cin >> b;
				vel += b;
				res += vel;
			}
			if (a == 2) {
				cin >> b;
				vel -= b;
				if (vel < 0) vel = 0;
				res += vel;
			}
		}
		
		cout << "#" << tt << " " << res << endl;
	}
}