#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;


constexpr int sz = 1 << 20; // 원소개수수보다 큰 2의 배수중 최소ㅗ
constexpr int treesz = sz << 1;
int n;

ll tree[treesz];

void init(int node, int s, int e) {

}
ll update(int idx, int val, int node = 1, int s = 1, int e = sz) {
    if (idx < s || idx > e) return tree[node];
    if (idx == s && idx == e) return tree[node] = val;//?
    if (s == e) return tree[node];
    int mid = s + e >> 1;
    return tree[node] = update(idx, val, node * 2, s, mid) + update(idx, val, node * 2 + 1, mid + 1, e);
}
ll query(int l, int r, int node = 1, int s = 1, int e = sz) {
    if (s > r || e < l) return 0;
    if (l <= s && e <= r) return tree[node];
    int mid = s + e >> 1;
    return query(l, r, node * 2, s, mid) + query(l, r, node * 2 + 1, mid + 1, e);
}
int main() {
    int m;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;


    for (int i =0 ; i< m; i++) {
        int a, b, c;

        cin >> a >> b >> c;
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