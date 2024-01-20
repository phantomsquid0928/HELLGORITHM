#include <bits/stdc++.h>

using namespace std;

int arr[4000][4000]; 
void func(int loop, int x, int y) {
	if (loop == 0) {
		arr[x][y] = 1;
		return;
	}
	func(loop - 1, x, y + 2 * pow(5, loop - 1)); //2 must be powed with loop val
	func(loop - 1, x + 1 * pow(5, loop - 1), y + 2 * pow(5, loop - 1)); //+1 m
	for (int i = 0; i < 5; i++) {
		func(loop - 1, x + 2 * pow(5, loop - 1), y + i * pow(5, loop - 1));
	}
	for (int i = 1; i < 4; i++) {
		func(loop - 1, x + 3 * pow(5, loop - 1), y + i * pow(5, loop - 1));
	}
	func(loop - 1, x + 4 * pow(5, loop - 1), y + 1 * pow(5, loop - 1));
	func(loop - 1, x + 4 * pow(5, loop - 1), y + 3 * pow(5, loop - 1));
	return;
}
int main() {
	int n;
	cin >> n;
	
	func(n, 0, 0);
	for (int i = 0; i < pow(5, n); i++) {
		for (int j = 0; j < pow(5, n); j++) {
			if (arr[i][j] == 1)
				cout << "*";
			else 
				cout << " ";
		}
		cout << '\n';
	}
}