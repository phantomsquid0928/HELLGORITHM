#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n;
	for (int i =0 ;i < n; i++){ 
		cin >> arr[i];
	}
	stack<int> s;
		
	int i = 0;
	int k = 0;
	int tt = 0;
	vector<char> res;
	res.push_back('+');
	s.push(k + 1);
	k++;
	while(i != n) {
//		cout << i << " ,," << k << endl;
		if (k > n) {
			tt = -1;
			break;
		}
		if (s.empty()) {
			res.push_back('+');
			s.push(k + 1);
			k++;
			continue;
		}
		if (s.top() != arr[i]) {
			res.push_back('+');
			s.push(k + 1);
			k++;
			continue;
		}
		if (s.top() == arr[i]) {
			res.push_back('-');
			s.pop();
			i++;
			continue;
		}
		
	}
	if (tt == -1) {
		cout << "NO" << endl;
	}
	else {
		for (auto i : res) {
			cout << i << '\n';
		}
	}
}