#include<iostream>

using namespace std;


int arr[8000][8000] = {0, };

void solve(int N, int old){ 
	if(N < 3) return;
	int t = N / 2;
	solve(t, old);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			arr[i + N][j + old - i - N] = arr[i][j + old - i];
			arr[i + N][j + old + N - i] = arr[i][j + old - i];

		}
	}
}
int main(){
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			arr[i][j] = -1;
		}
	}
	
	
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int k = 0; k < 2 * N - i; k++) {
			arr[i][k] = -1;
		}
		sum += N - i;
		for (int j = 0; j < 2 * i + 1; j++) {
			arr[i][j + sum] = 1;
			if (i == 1 && j == 1) {
				arr[i][j + sum] = -1;
			}
		}
	}
	
	
	solve(N/2, N);
	for (int i = 0; i < N; i++) {
		if (i != 0) {
			cout << endl;
		}
		for (int j = 1; j < 2 * N; j++) {
			if (arr[i][j] == 0) continue;
			if (arr[i][j] == -1) {
				cout << " ";
			}
			if (arr[i][j] == 1) {
				cout << "*";
			}
		}
	}
}