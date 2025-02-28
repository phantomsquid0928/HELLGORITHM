#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

constexpr int sz = 1 << 17;
constexpr int treesz = sz << 1;

pair<int, int> tree[treesz];

vector<int> arr;

void init(int node = 1, int s = 1, int e = sz) {
    if (s == e && s > arr.size()) {
        tree[node] = {0, 1000000001};
        return;
    }
    if (s == e) {
        tree[node] = {arr[s - 1], arr[s - 1]};
        return;
    }
    int m = s + e >> 1;
    init(node * 2, s, m);
    init(node * 2 + 1, m + 1, e);
    tree[node].first = max(tree[node * 2].first, tree[node * 2 + 1].first);
    tree[node].second = min(tree[node * 2].second, tree[node * 2 + 1].second);
}
void update(int idx, int val) {
    idx += sz - 1, tree[idx] = {val, val};
    while(idx /= 2) {
        tree[idx].first = max(tree[idx * 2].first, tree[idx * 2 + 1].first);
        tree[idx].second = min(tree[idx * 2].second, tree[idx * 2 + 1].second);
    }
}

pair<int, int> query(int l, int r, int node = 1, int s = 1, int e = sz) {
    if (s > r || e < l) return {0, 1000000001};
    if (l <= s && e <= r) {
        return tree[node];
    }
    int m = s + e >> 1;
    auto a = query(l, r, node * 2, s, m);
    auto b = query(l, r, node * 2 + 1, m + 1, e);
    return {max(a.first, b.first), min(a.second, b.second)};
}
int main() {
    int n, m;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    
    for (int i =0 ;i < n ;i++) {
        int in;
        cin >> in;

        arr.push_back(in);
    }

    init();

    // for (int i = 1; i < 34; i++) {
    //     cout << tree[i].first << " ";
    // }
    // cout << endl;

    while(m--) {
        int a, b;
        cin >> a >> b;
        auto res = query(a, b);
        cout << res.second << " " << res.first << endl;
    }
}