#include <bits/stdc++.h>

using namespace std;

int arr[20000001];
int main() {
//	int n;
//	set<int> cards;
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> n;
//	for (int i = 0;i < n;i++) {
//		int temp;
//		cin >> temp;
//		cards.insert(temp);
//	}
//	int m;
//	cin >> m;
//	for (int i = 0 ;i < m; i++) {
//		int temp;
//		cin >> temp;
//		cout << cards.count(temp) << " ";
////		if (cards.count(temp) != 0) cout << 1 << " ";
////		else cout << 0 << " "; 
//	}
//}
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i =0 ;i < n; i++) {
		int temp;
		cin >> temp;
		arr[temp + 10000000]++;
	}
	int m;
	cin >> m;
	for (int i = 0;i < m; i++) {
		int temp;
		cin >>temp;
		if (arr[temp + 10000000] != 0) {
			cout << arr[temp + 10000000] << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
}