#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

// sz : n보다 크거나 같은 2^k 인 수
// 13만 -> 1 << 17 (131072) 100만 -> 1 << 20 (1048576)
constexpr int sz = 1 << 20; // 100만
constexpr int treesz = sz << 1;

ll tree[treesz];

void update(int idx, ll v) { 
    //+= sz - 1 for [1, sz] idx, += sz for [0, sz - 1]
    idx += sz - 1, tree[idx] = v;
    while(idx /= 2) tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

ll query(int l, int r) {
    ll res = 0;
    for (l += sz - 1, r += sz - 1; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res += tree[l++];
        if (r % 2 == 0) res += tree[r--];
    }
    return res;
}

int main() {
    int n, m;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n >> m;

    for (int i= 0 ;i < m; i++) {
        int a, b, c;

        cin >> a >> b >>c;

        if (a == 0) {
            int bb = min(b, c);
            int cc = max(b, c);

            cout << query(bb, cc) << endl;
        }
        else {
            update(b, (ll)c);
        }
    }
}