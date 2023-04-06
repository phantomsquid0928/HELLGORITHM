#include <bits/stdc++.h>

using namespace std;

int notprime[1300000] = {1, 1, };
void getPrimes() {
	for (int i = 2; i < sqrt(1300000); i++) {
		for (int j = 2; i * j < 1300000; j++) {
			notprime[i * j] = 1;
		}
	}
}
int ispalin(string s, int i, int j) {
	if (i >= j) return 1;
	if (j - i == 1 && s[i] == s[j]) return 1;
	if (s[i] != s[j]) return 0;
	return ispalin(s, i + 1, j - 1);
}
int main() {
	int n;
	cin >> n;
	getPrimes();
	
	for (int i = n; ; i++) {
		if (notprime[i] != 1) {
			string temp = to_string(i);
			if (ispalin(temp, 0, temp.length() - 1)) {
				cout << i;
				return 0;
			}
		}
	}
}