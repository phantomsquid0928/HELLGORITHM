#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

constexpr int treesz = 5000000;

struct treenode {
	int l, r;
	ll val;
	treenode() {
		l = -1;
		r = -1;
		val = 0;
	}
};

treenode tree[treesz];
int used = 1;
//unordered_map<int, int> info;
vector<ll> arr;

void update(ll idx, int val, int node = 0, ll s = 0, ll e = 10e17 + 4) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[node].val += val;
		return;
	}
	ll m = s + e >> 1;
	
	if (idx < m + 1) {
		if (tree[node].l == -1) tree[node].l = used++;
		update(idx, val, tree[node].l, s, m);
	}
	else {
		if (tree[node].r == -1) tree[node].r = used++;
		update(idx, val, tree[node].r, m + 1, e);
	}
	ll a = tree[node].l != -1 ? tree[tree[node].l].val : 0;
	ll b = tree[node].r != -1 ? tree[tree[node].r].val : 0;
	tree[node].val = a + b;
}

ll query(ll l, ll r, int node = 0, ll s = 0, ll e = 10e17 + 4) {
	if (node == -1) return 0;
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node].val;
	
	ll m = s + e >> 1;
	return query(l, r, tree[node].l, s, m) + query(l, r, tree[node].r, m + 1, e);
}

ll query2(ll k, int node=0, ll s = 0, ll e = 10e17 + 4) {
	if (node == -1) return 0;
	if (s == e) return s;
	ll m = s + e >> 1;
//	if (tree[node].l != -1) {
		if (tree[tree[node].l].val < k) return query2(k - tree[tree[node].l].val, tree[node].r, m + 1, e);
		return query2(k, tree[node].l, s, m);
//	}
//	return query2(k, tree[node].r, m + 1, e);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n,m;
	cin >> n>>m;
	
	arr.push_back(0);
	
	for (int i =0 ;i < n; i++) {
		int in;
		cin >> in;
		update(in, 1);
		arr.emplace_back(in);
	}
	
	while(m--) {
		int in;
		cin >> in;
		if (in == 1) {
			ll i, x;
			cin >> i >> x;
			ll cur = arr[i];
			ll n = cur + x;
			update(cur, -1);
			update(n, 1);
			arr[i] = n;
			
		}if (in == 2) {
			ll i, y;
			cin >> i >> y;
			ll cur = arr[i];
			ll n = cur - y;
			update(cur, -1);
			update(n, 1);
			arr[i] = n;
		}if (in == 3) {
			ll l, r;
			cin >> l >> r;
			cout << query(l, r) << endl;
		}if (in == 4) {
			int t;
			cin >> t;
			cout << query2(n - t + 1) << endl;
		}
	}
}
