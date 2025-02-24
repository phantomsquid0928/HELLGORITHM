#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

constexpr int sz = 2 << 20;
constexpr int treesz = sz << 1;

vector<ll> arr;
ll seg[treesz];

void init(int node = 1, int s = 1, int e = sz) {
    if (s == e && s > arr.size()) {
        seg[node] = 0;
        return;
    }
    if (s == e) {
        seg[node] = arr[s - 1];
        return;
    }
    int m = s + e >> 1;
    init(node * 2, s, m);
    init(node * 2 + 1, m + 1, e);
    seg[node] = seg[node * 2]+ seg[node * 2 + 1];
}
void update(int idx, ll val, int node = 1, int s = 1, int e = sz) {
//     idx += sz, seg[idx] = val;

//     while(idx /= 2) seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
// }
    if (s == e && s == idx) {
        seg[node] = val;
        return;
    }
    if (idx < s || idx > e) return;
    int m = s + e >> 1;
    update(idx, val, node * 2, s, m);
    update(idx, val, node * 2 + 1, m + 1, e);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
ll query(int l, int r, int node = 1, int s = 1, int e = sz) {
    if (s > r || e < l) return 0;//smaller thn min of input
    if (l <= s && e <= r) return seg[node];
    int m = s + e >> 1;
    auto a = query(l, r, node * 2, s, m);
    auto b = query(l, r, node * 2 + 1, m + 1, e);

    // cout << "comp " << a.first << " " << b.first  << "  : returning : " << ((a < b) ? a.first : b.first) << endl;

    return a + b;
}

int main() {
    int n, m, k;
    // pair<int, int> a = {1000, 5};
    // pair<int, int> b = {1044, -1};
    // cout << (a > b ? 'a' : 'b') << endl;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    

    for (int i = 0;i <n; i++) {
        ll in;
        cin >> in;
        arr.push_back(in);
    }
    memset(seg, 0, sizeof seg);
    init();

    // for (int i = 1; i <= 15; i++) {
    //     cout << seg[i].second << " ";
    // }
    // cout << endl;

	int t = m + k;
    while(t--){ 
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            update(b, c);
        }
        else {
            ll res = query(b, c);
            // cout << res.first << endl;
            cout << res << endl;
        }

        // for (int i = 1; i<= 16; i++) {
        //     cout << seg[i].second << " ";
        // }
        // cout << endl;
    }
}