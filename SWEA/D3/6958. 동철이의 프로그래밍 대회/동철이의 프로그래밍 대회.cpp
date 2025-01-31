#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	
	cin >> t;
	
	
	for (int tt= 1; tt <=t ; tt++) {
		int n, m;
		
		cin >> n >> m;
		
		int maxval = 0;
		int maxcnt = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				int in;
				cin >> in;
				
				sum += in;
			}
			if (maxval < sum) {
				maxval = sum;
				maxcnt = 1;
			}
			else if (maxval == sum) {
				maxcnt++;
			}
		}
		
		cout << "#" << tt << " " << maxcnt << " " << maxval << endl;
	}
}