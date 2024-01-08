#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
deque<int> d;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 1) {
			d.push_front(n - i);
		}
		if (arr[i] == 2) {
			int temp = d.front();
			d.pop_front();
			d.push_front(n - i);
			d.push_front(temp);
		}
		if (arr[i] == 3) {
			d.push_back(n - i);
		}
	}
	for (auto i : d) {
		cout << i << " ";
	}
}