#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> arr;
int chk[2001];
unordered_map<int, int> m;

int main() {
	int n;
	cin >> n;
	
	for (int i = 0;i < n; i++) {
		int in; cin >> in;
		
		arr.push_back(in);
		if (m.count(in)) m[in]++;
		else m.insert({in, 1});
	}
	
	int cnt = 0;
	int t = arr.size();
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (i == j) continue;
//			cout << i << " " << j << endl;
			int a = arr[i];
			int b = arr[j];
			
			if (m.count(a - b)) {
				if (m[a - b] == 1) {
					if (a - b == a || a - b == b) continue;
					chk[i] = 1;
				}
				else if (m[a - b] == 2) {
					if (a - b == a && a - b == b) continue;
					chk[i] = 1;
				}
				else chk[i] = 1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (chk[i]) cnt++;
	}
	
	cout << cnt << endl;
}