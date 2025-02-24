#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

constexpr int sz = 1 << 17;
constexpr int treesz = sz << 1;

vector<int> arr;
int tree[treesz];

void init(int node = 1, int s = 1, int e = sz) {
	if (s == e && s > arr.size()) {
		tree[node] = 1000000001;
		return;
	}
	if (s == e) {
		tree[node] = arr[s - 1];
		return;
	}
	int m = s + e >> 1;
	
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
void update(int idx, int val) {
//	cout << "modifying " << idx << " " << val << endl;
	idx += sz - 1, tree[idx] = val;
	while(idx /= 2) {
		int a = (tree[idx * 2] == 0) ? 1000000001 : tree[idx * 2];
		int b = (tree[idx * 2 + 1] == 0) ? 1000000001 : tree[idx * 2 + 1];
		tree[idx] = min(a, b);
	}
}
int query(int l, int r, int node = 1, int s = 1, int e = sz) {
	if (e < l || s > r) return 1000000001;
	if (l <= s && e <= r) return tree[node];
	
	int m = s + e >> 1;
	int a = query(l, r, node * 2, s, m);
	int b = query(l, r, node * 2 + 1, m + 1, e);
	
	int aa = (a == 0) ? 1000000001 : a;
	int bb = (b == 0) ? 1000000001 : b;
	return min(aa, bb);
}

int main() {
	int n;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	
	for (int i = 0; i <  n; i++ ){
		int in;
		cin >> in;
		arr.push_back(in);
	}
	
	init();
	
//	for (int i = 1; i<= 20; i++) {
//		cout << tree[i] << " ";
//	}
//	cout << endl;
	
	int m;
	cin >> m;
	
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
		 	update(b, c);
		}
		else {
			cout << query(b, c) << endl;
		}
//		for (int i = 1; i<= 20; i++) {
//		cout << tree[i] << " ";
//	}
//	cout << endl;
	}
}