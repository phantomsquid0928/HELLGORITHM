#include <bits/stdc++.h>

using namespace std;

int notprimes[500001];
long long dp[2][500001] = {}; // 500000
void getPrimes() {
	notprimes[0] = 1;
	notprimes[1] = 1;
	for (int i = 2; i < sqrt(500000); i++) {
		for (int j = 2; i * j < 500000; j++) {
			notprimes[i * j] = 1;
		}
	}
}
int main() {
	int n;
	int size = 0;
	
	getPrimes();
	cin >> n;
	int arr[n];
	int hist[500001] = {};
	dp[0][0] = 1;
	
	int sum = 0;
	for (int i = 0; i < n; i++){
	    int temp;
	    cin >> temp;
	    sum += temp;
	    
	    if (hist[temp] != 0) {
	        hist[temp]++;
	        continue;
        }
	    arr[size] = temp;
	    hist[temp] = 1;
	    size++;
	}
	int max = 0;
	for (int i = 0; i < size; i++){
		for(int j = 0; j <= 500000; j++) {
		    dp[(i + 1) % 2][j] = 0;
			for (int k = 0; k <= hist[arr[i]]; k++) {
			    if (j >= k * arr[i]) {
			        dp[(i + 1) % 2][j] += dp[i % 2][j - k * arr[i]];
                }
            }
//            for (int k = 1; k < hist[last] -1; k++) {
//                temp += dp[i-1][j - (k + 1) * arr[i - dup]];
//            }
		}
        //cout << "last" << last << "arr" << i - dup << endl;
    }
    long long res = 0;
    for (int i = 0; i < 500000; i++) {
        if (notprimes[i] != 1) {
            res += dp[(size)% 2][i];
        }
    }
    cout << res << endl;

	
//	for (int i = 0; i < n + 1; i++) {
//	    for (int j = 0; j <= 50; j++) {
//	        cout << dp[i][j] << " "; 
//        }
//        cout << endl;
//    }
  //  cout << hist[1] << endl;
    
}