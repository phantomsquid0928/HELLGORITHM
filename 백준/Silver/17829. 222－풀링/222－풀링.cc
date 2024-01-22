#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1030][1030];
int solve(int i, int j, int size) {
	if (size == 2) {
		int lst[4] = {arr[i][j], 
							arr[i + 1][j],
							 arr[i][j + 1],
							  arr[i + 1][j + 1]};
		sort(lst, lst + 4);
		return lst[2];
	}
	else {
		int lst[4] = {solve(i, j, size / 2), 
					solve(i + size/ 2, j, size / 2),
					 solve(i, j + size/2, size / 2), 
					 solve(i + size / 2, j + size / 2, size / 2)};
		sort(lst, lst + 4);
		return lst[2];
	}
}
int main() {
	cin >> n;
	for (int i = 0;i <n; i++) {
		for (int j= 0; j <n;j++) {
			cin >> arr[i][j];
		}
	}
	
	cout << solve(0, 0, n);
}