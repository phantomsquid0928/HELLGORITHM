#include <bits/stdc++.h>

using namespace std;

int arr[1000];
int main() {
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; tt++) {
		int n;
		cin >> n;
		
		int old = 0;
		bool exists = false;
		
		int updiff = 0;
		int downdiff = 0;
		
		for (int i = 0; i <n ;i++) {
			cin >> arr[i];
			if (i  == 0 ) continue;
			
			int diff = arr[i] - arr[old];
			if (diff > 0) {
				exists = true;
				updiff = max(updiff, diff);
			}
			else if (diff < 0) {
				exists = true;
				downdiff = max(downdiff, -diff);
			}
			else {
				
			}
			old = i;
		}
		if (exists) {
			cout << "#" << tt << " " << updiff << " " << downdiff << endl;
		}
		else {
			cout << "#" << tt << " " << 0 << " " << 0 << endl;
		}
	}
}