#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int itt=  1; itt <= t; itt++) {
		int res = 0;
		
		string s;
		cin >> s;
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '1') {
				res++;
				for (int j = i; j < s.length(); j++) {
					if (s[j] == '1') s[j] = '0';
					else s[j] = '1';
				}
			}
		}
		
		cout << "#" << itt << " " << res << endl;
	}
}