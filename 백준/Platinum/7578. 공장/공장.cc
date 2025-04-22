#include <bits/stdc++.h>
#define ll long long
using namespace std;

constexpr int sz = 1 << 19;
constexpr int treesz = sz << 1;

ll tree[treesz]; // counting tree
unordered_map<int, int> ids;

void update(int idx, int val) {
    idx += sz - 1, tree[idx] = val;
    while(idx /= 2) {
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}
ll query(int l, int r, int node =1, int s = 1, int e = sz) {
    if (s > r || e < l) return 0;
    if (l <= s && e <= r) {
        return tree[node];
    }
    int m = s + e >> 1;
    return query(l, r, node * 2, s, m) + query(l, r, node * 2 + 1, m + 1, e);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        ids[in] = i;
    }

    ll sum = 0;
    for (int i = 1; i <= n;i ++) {
        int in;
        cin >> in;
        int id = ids[in];
        sum += query(id, 500000);
        update(id, 1);
    }
    cout << sum << endl;
}