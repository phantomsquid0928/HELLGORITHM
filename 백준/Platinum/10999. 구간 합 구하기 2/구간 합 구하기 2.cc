#include <iostream>
#include <vector>

using namespace std;

#define ll long long 
#define endl '\n'

constexpr int sz = 1 << 20;
constexpr int treesz = sz << 1;

ll tree[treesz];
ll lazy[treesz];

vector<ll> arr;
void init(int node = 1, int s = 1, int e = sz) {
	if (s == e && s > arr.size()) return;
	if (s == e) {
		tree[node] = arr[s - 1];
		return;
	}
	int m = s + e >> 1;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void push(int s, int e, int node) {
	if (lazy[node] == 0) return;
	
	tree[node] += (e - s + 1) * lazy[node];
	if (s != e) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}
void update_range(int l, int r, ll val, int node = 1, int s = 1, int e = sz) {
	push(s, e, node);
	if (s > r || e < l) return;
	if (l <= s && e <= r) {
		lazy[node] += val;
		push(s, e, node);
		return;
	}
	int m = s + e >> 1;
	update_range(l, r, val, node * 2, s, m);
	update_range(l, r, val, node * 2 + 1, m + 1, e);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll query(int l, int r, int node = 1, int s = 1, int e = sz) {
	push(s, e, node);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) {
		return tree[node];
	}
	int m = s + e >> 1;
	return query(l, r, node * 2, s, m) + query(l, r, node * 2 + 1, m + 1, e);
}
int main() {
	int n, m, k;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		ll in;
		cin >> in;
		arr.emplace_back(in);
	}

	init();

	int q = m + k;

	while (q--) {
		int a;
		cin >> a;
		if (a == 2) {
			ll b, c;
			cin >> b >> c;

			cout << query(b, c) << endl;
		}
		if (a == 1) {
			ll b, c, d;
			cin >> b >> c >> d;
			update_range(b, c, d);
		}
	}
}