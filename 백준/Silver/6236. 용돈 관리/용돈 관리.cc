#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int moneys[100030];
int temp[100030];



int solve(int N, int M, int mid, int cnt, int day) { //whether succeed
	
	int cur = mid; 
	int tempcnt = cnt;
	int failchk = 0;
//	int range = 0;
	for (int j = day; j < N; j++) {
		//if (tempcnt >= N) continue;
		if (cur - moneys[j] < 0) {
			if (mid < moneys[j]) {
				failchk = -1;
				break;
			}
			tempcnt++;
			cur = mid - moneys[j];	
		}
		else {
			cur -= moneys[j];
		}
	}
	if (failchk == -1) return -2;
	if (tempcnt == M) return 0;
	if (tempcnt < M) return -1;
	return 1;
}
int solve2(int N, int M, int moneys, int moneye) {
	int mid = (moneys + moneye) / 2;
	if (moneys > moneye) {
		return mid + 1;
	}
	int res = solve(N, M, mid, 1, 0);
	
	//cout << res << endl;
	if (res == -2) {
		//cout << mid << "~" << moneye<< endl;
		return solve2(N, M, mid+1, moneye);
	}
	if (res == -1) {
		//cout << mid << "~" << moneye<< endl;
		return solve2(N, M, moneys, mid-1);
	}
	if (res == 0) {
		return solve2(N, M, moneys, mid -1);
	}
	if (res == 1) {
		//cout << moneys << "~" << mid << endl;
		return solve2(N, M, mid+1, moneye);
	}
}

int main(){
	int N, M;
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> moneys[i];
		temp[i] = moneys[i];
	}
	
	sort(temp, temp + N);
	int cnt = 0;
	int res = 0;
	int sum = 0;
	int t = temp[N-1];
	for (int i = 0; i < N; i++) {
		sum += temp[i];
	}
	
	cout << solve2(N, M, t, sum);
}