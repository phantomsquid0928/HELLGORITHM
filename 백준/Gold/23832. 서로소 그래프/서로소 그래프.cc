#include <bits/stdc++.h>

using namespace std;

int notprime[50001];
int parts[50001];
int main() {
	int n;
	cin >>n;
	
	notprime[1] = -1;
	for (int i = 2; i * i <= n; i++) {
		if (!notprime[i]) {
			for (int j = i + i; j <= n; j += i) {
				notprime[j] = i;
			}
		}
		
	}
	int sum = 0;
	
	for (int i = n; i >= 2; i--) {
		int tmp = i;
		memset(parts, 0, sizeof(parts));
		vector<int> factors;
		factors.clear();
		while(notprime[tmp]) {
			if (parts[notprime[tmp]] == 0) {
				factors.push_back(notprime[tmp]);
			}
			parts[notprime[tmp]] = 1;
			tmp /= notprime[tmp];
		}
		if (parts[tmp] == 0 || factors.empty()) {
			factors.push_back(tmp);
		}
		
		if (!notprime[i]) {
//			cout << i - 1 << endl;
			sum += i - 1;
			continue;
		}
		double totient = i;
//		cout << "factor of " << i << " : ";
		for (auto t : factors) {
//			cout << t << " ";
			totient = totient * (1 - 1.0 / t);
		}
//		cout << endl;
//		cout << totient << endl;
		sum += (int)totient;
//		cout << endl;
		
	}
	cout << sum << endl;
}