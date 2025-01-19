#include <bits/stdc++.h>

using namespace std;

int nums[26] = {};
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	nums['A' - 'A'] = 1;
	nums['D' - 'A'] = 1;
	nums['O' - 'A'] = 1;
	nums['P' - 'A'] = 1;
	nums['Q' - 'A'] = 1;
	nums['R' - 'A'] = 1;
	
	nums['B' - 'A'] = 2;
	
	int n;
	cin >> n;
	
	for (int t = 1; t <= n; t++) {
		string a, b;
		cin >> a >> b;
		
		bool res = true;
		
		if (a.length() != b.length()) {
			cout << "#" << t << " ";
			cout << "DIFF" << '\n';
			continue;
		}
		for (int i = 0; i < a.length(); i++) {
			char aa = a[i];
			char bb = b[i];
			
			if (nums[aa - 'A'] != nums[bb - 'A']) {
				res = false;
				break;
			}
		}
		
		cout << "#" << t << " ";
		if (res) cout << "SAME" << '\n';
		else cout << "DIFF" << '\n';
	}
}