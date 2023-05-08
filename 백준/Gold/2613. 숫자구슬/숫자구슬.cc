#include <bits/stdc++.h>

using namespace std;

int a[400] = {};
int s[400] = {};
int res[400] = {};
int solve(int mid, int n, int m) {
	int i;
	int sum = 0;
	int j = 1;
	for (i = 1; i <= n; i++) {
		sum += a[i];
		if (a[i] > mid) {
			return -1;
		}
		if (sum > mid) {
			sum = a[i];
			res[j] = i - 1;
			j++;
		}
	}
	res[j] = i - 1;
	if (j > m) {
		return -1;
	}
	if (j == m) {
		return j;
	}
	else {
		return j;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	int maxl = 0;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		a[i] = temp;
		s[i] += s[i - 1] + temp;
		if (maxl < temp) {
			maxl = temp;
		}
	}
	int start = 1;
	int end = 100000;
	int res2 = 0;
	int mid;

	for (int i = 0; i < 50; i++) {
		mid = (start + end)>>1;
		//cout << start << " " << end << endl;
		res2 = solve(mid, n, m);
		if (res2 == -1) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	res2 = solve(end, n, m);
	vector<int> trueres;
	for (int i = 1; i <= res2; i++) {
		trueres.push_back(res[i] - res[i - 1]);
	}
	
	if (res2 != m) {

		int need = m - res2;
		for (int i = 0; i < trueres.size(); i++) {
			if (trueres[i] > 1) {
				while(true) {
					if (need == 0) break;
					if (trueres[i] == 1) break;
					trueres[i] = trueres[i] - 1;
					trueres.insert(trueres.begin() + i, 1);
					need--;
				}
			}
		}
	}
	int idx = 0;
	int maxt = 0;
	for (int i = 0; i < trueres.size(); i++) {
		maxt = max(maxt, s[idx + trueres[i]] - s[idx]);
		idx += trueres[i];
	}
	cout << maxt << '\n';
	for (auto i = trueres.begin(); i != trueres.end(); i++) {
		cout << *i << " ";
	}
}