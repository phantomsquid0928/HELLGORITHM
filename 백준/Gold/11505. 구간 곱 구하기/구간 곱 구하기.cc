#include <bits/stdc++.h>
#define ll long long 
#define endl '\n'

using namespace std;

struct treenode {
	ll val;
	int l, r;
	treenode() : val(0), l(-1), r(-1){
	}
};
//update를 주어진 값으로 인덱스를 부여하는데, 주어진 값이 10억 이상이다 -> dynamic seg...

constexpr int sz = 1 << 20;
constexpr int treesz = sz << 1;
treenode tree[treesz];
int used = 1;

void update(int idx, int val, int node = 0, int s = 0, int e = sz - 1) {
	if (s == e) {
		tree[node].val = val;
		return;
	}
	int m = s + e >> 1;
	if (idx <= m) {
		if (tree[node].l == -1) tree[node].l = used++;
		update(idx, val, tree[node].l, s, m);
	}
	else {
		if (tree[node].r == -1) tree[node].r = used++;
		update(idx, val, tree[node].r, m +1, e);
	}
	ll a = tree[node].l != -1 ? tree[tree[node].l].val : 0;
	ll b = tree[node].r != -1 ? tree[tree[node].r].val : 0;
	tree[node].val = (a * b) % 1000000007; 
}

ll query(int l, int r, int node = 0, int s = 0, int e = sz - 1) {
	if (s > r || e < l) return 1;
	if (l <= s && e <= r) {
		return tree[node].val;
	}
	int m = s + e >> 1;
	return (query(l, r, tree[node].l, s, m) * query(l, r, tree[node].r, m + 1, e)) % 1000000007;
}


int main( ){
	int n, m, k;
	
	cin >> n >> m >> k;
	
	for (int i= 0 ;i < n; i++) {
		int in;
		cin >> in;
		update(i, in);
	}
	
	for (int i = 0;i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if (a == 1) {
			update(b - 1, c);
		}
		else {
			cout << query(b - 1, c - 1) << endl;
		}
	}
}