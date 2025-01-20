#include <bits/stdc++.h>

using namespace std;

int main() {
	for (int test = 1; test <= 10; test++) {
		int n;
		cin >> n;
		string s;
		string res = "";
		cin >> s;
		int resend = -1;
		int send = 0;
		
		while(1) {
			if (send >= n) break;
//			cout << res << endl;
			char c = s[send];
			if (resend < 0 || res[resend] != c) {
				res.append(string(1, c));
				resend++;
				send++;
			}
			else {
//				cout << "here" << endl;
//				res.append(string(1, c));
				while(1) {
					if (resend < 0) break;
					if (send >= n) break;
					
//					cout << res[resend] << " " << c << endl;
					if (res[resend] != c) break;
					resend--;
//					cout << "com" << res << endl;
					res = res.substr(0, res.length() - 1);
					c = s[++send];
//					res.append(string(1, c));
				}
			}
		}
		cout << "#" << test << " " << res << endl;
	}
}