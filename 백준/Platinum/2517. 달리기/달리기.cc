#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

struct treenode {
	int l, r;
	ll val;
	treenode () : l(-1), r(-1), val(0) {
	}
};
//constexpr int sz = 1 << 20;
//constexpr int treesz = sz << 1;

treenode tree[6000000];
int used = 1;

void update(int idx, int val, int node = 0, int s = 1, int e = 1000000001) {
//	if (s > idx || e < idx) return;
	if (s == e) {
		tree[node].val = 1;
		return;
	}
	int m = s + e >> 1;
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
//int query(int k, int node = 0, int s = 1, int e = 1000000000) {
//	if (s == e) return s;
//	int m = s + e >> 1;
//	if (tree[node].l != -1) {
//		if (tree[tree[node].l].val < k) {
//			return query(k - tree[tree[node].l].val, tree[node].r, m + 1, e);
//		}
//		return query(k, tree[node].l, s, m);
//	}
//	else {
//		return query(k, tree[node].r, m + 1, e);
//	}
//}
ll query2(int l, int r, int node = 0, int s = 1, int e = 1000000001) {
	if (s > r || e < l) return 0;
	if (node == -1) return 0;
	if (l <= s && e <= r) {
		return tree[node].val;
	}
	int m = s + e >> 1;
	ll a = tree[node].l != -1 ? query2(l, r, tree[node].l, s, m) : 0;
	ll b = tree[node].r != -1 ? query2(l, r, tree[node].r, m + 1, e) : 0;
	return a + b;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
//	vector<array<int, 2>> arr;
	for (int i =0; i < n ;i++) {
		int in;
		cin >> in;
//		arr.push_back({in, i});
		update(in, i);
		cout << query2(in, 1000000001) << endl;
	}
}