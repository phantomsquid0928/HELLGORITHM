#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

constexpr int sz = 1 << 20;
constexpr int treesz = sz << 1;
ll tree[treesz];

vector<ll> arr;

void init(int node = 1, int s = 1, int e = sz) {
	if (s == e && s > arr.size()) {
		return;
	}
	if (s == e) {
		tree[node] = arr[s - 1];
		return;
	}
	int m = s + e >> 1;
	
	init(node * 2, s, m);
	init(node * 2 + 1, m +1, e);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void update(int idx, ll val, int node = 1, int s = 1, int e = sz) {
	idx += sz - 1, tree[idx] = val;
	while(idx /= 2) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}
//void update2(int idx, ll val, int node = 1, int s = 1, int e = sz) {
//	if (s == e && s == idx) {
//		tree[node] = val;
//		return;
//	}
//	if (s == e) return;
//	int m = s + e >> 1;
//	update2(idx, val, node * 2, s, m);
//	update2(idx, val, node * 2 + 1, m + 1, e);
//	tree[node] = tree[node * 2] + tree[node * 2 + 1];
//}

ll query(int l, int r, int node = 1, int s = 1, int e = sz) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node];
	int m = s + e >> 1;
	
	return query(l, r, node * 2, s, m) + query(l, r, node * 2 + 1, m + 1, e);
}

int main() {
	int n, m, k;
	int q;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	q = m + k;
	memset(tree, 0, sizeof tree);
	for (int i=0 ; i< n; i++){
		ll in;
		cin >> in;
		arr.push_back(in);
	}
//	cout << arr[0] << endl;
	init();
	
//	for (int i = 1; i < 40; i++) {
//			cout << tree[i] << " ";
//		}
//		cout << endl;
	
	
	while(q--) {
		ll a, b, c;
		cin >> a >> b >> c;
		
		if (a == 2) {
			cout << query(b, c) << endl;
		}
		else {
			update(b, c);
		}
		
//		for (int i = 1; i < 40; i++) {
//			cout << tree[i] << " ";
//		}
//		cout << endl;
	}
}