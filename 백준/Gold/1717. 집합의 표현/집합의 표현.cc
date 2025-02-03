#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int union_find[1000002];
int ranks[1000002];

int find(int a) {
	if (a == union_find[a]) return a;
	
	return union_find[a] = find(union_find[a]);
}
void _union(int a, int b) {
	int t = find(a);
	int tt = find(b);
	
	union_find[t] = tt;
//	if (t == tt) return;
//	
//	if (ranks[t] > ranks[tt]) {
//		union_find[tt] = t;
//	}
//	else if (ranks[t] < ranks[tt]) {
//		union_find[t] = tt;
//	}
//	else {
//		union_find[tt] = t;
//		ranks[t]++;
//	}
}
int main() {
	int n, m;
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 0;i <= n; i++) {
		union_find[i + 1] = i + 1;
	}
	
	for (int i =0 ; i< m; i++) {
		int a, b, c;
		
		cin >> a >> b >> c;
		
		if (a == 0) {
			_union(b + 1, c + 1);
		}
		if (a == 1) {
			if (find(b + 1) == find(c + 1)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}