#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

constexpr int sz = 1 << 20;
constexpr int treesz = sz << 1;

vector<int> arr;

ll tree[treesz];
ll lazy[treesz];

void push(int s, int e, int node) {
    if (lazy[node]) {
        tree[node] += (e - s + 1) * lazy[node];
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }
}

void init(int node = 1, int s = 1, int e = arr.size()) {
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
void update(int l, int r, int val, int node = 1, int s = 1, int e = arr.size()) {
    push(s,e,node);
    if (s > r || e < l) return;
    if (l <= s && e <= r) {
        lazy[node] += val;
        push(s, e, node);
        return;
    }

    int m = s + e >> 1;
    update(l, r, val, node * 2, s, m);
    update(l, r, val, node * 2 + 1, m + 1, e);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int l, int r, int node = 1, int s = 1, int e = arr.size()) {
    push(s, e, node);
    if (s > r || e < l) return 0;
    if (l <= s && e <= r) return tree[node];

    int m = s + e >> 1;

    return query(l, r, node * 2, s, m) + query(l, r, node * 2 + 1, m + 1, e);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0;i < n; i++) {
        int in;
        cin >> in;
        arr.emplace_back(in);
    }
    init();

   
    int m;
    cin >> m;

    while(m--) {
        int a;
        cin >> a;
        //cout << a << endl;
        if (a == 1) {
            int b, c, d;
            cin >> b >> c >> d;
            update(b, c, d);
        }

        else {
            int b;
            cin >> b;
            cout << query(b, b) << endl;
        }
    }
}