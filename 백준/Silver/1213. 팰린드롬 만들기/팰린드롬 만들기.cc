#include<bits/stdc++.h>

using namespace std;

char str[51];
int cnt = 0;
int solve(string s, int *cnts) {
	int chk = 0;
	int target = 0;
	for (int i = 0; i < 30; i++) {
		if (cnts[i] > 1) {
			target = i;
			chk =1;
			break;
		}
	}
	if (chk == 0) {
		for (int i = 0; i < 30; i++) {
			if (cnts[i] == 1 && chk == 1) {
				return -1;
			}
			if (cnts[i] == 1 && chk == 0) {
				target = i;
				chk =1;
			}
		}
		if (chk == 1) {
			str[cnt] = target + 65;
			cnt++;
			return 1;
		}
		return 1;
	}
	cnts[target] -= 2;
	str[cnt] = target + 65;
	cnt++;
	int ret = solve(s, cnts);
	str[cnt] = target + 65;
	cnt++;
	return ret;
}
int main() {
	string s;
	cin >> s;
	int cnts[30] = {};
	for (int i = 0 ; i < s.length(); i++) {
		cnts[s[i] - 65] += 1;
	}
	int res = solve(s, cnts); 
	if (res != -1) {
		for (int i = 0;i < cnt; i++) {
			printf("%c", str[i]);
		}
	}
	else {
		printf("I'm Sorry Hansoo");
	}
}