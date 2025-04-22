#include <bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int sz = 1 << 17;
constexpr int treesz = sz << 1;

array<int, 2> tree[treesz];

vector<int> arr;

array<int, 2> query(int l, int r, int node = 1, int s = 1, int e = arr.size()) {
    if (s > r || e < l) return {INT_MAX, 0};
    if (l <= s && e <= r) return tree[node];
    
    int m = s + e >> 1;
    
    auto a = query(l, r, node * 2, s, m);
    auto b = query(l, r, node * 2 + 1, m + 1, e);
    if (a[0] > b[0]) return b;
    else return a;
}
void init(int node = 1, int s = 1, int e = arr.size()) {
    if (s == e && s > arr.size()) return;
    if (s == e) {
        tree[node] = {arr[s - 1], s};
        return;
    }
    int m = s + e >> 1;
    init(node * 2, s, m);
    init(node * 2 + 1, m + 1, e);
    int a = tree[node * 2][0] != -1 ? tree[node * 2][0] : INT_MAX;
    int b = tree[node * 2 + 1][0] != -1 ? tree[node * 2 + 1][0] : INT_MAX;
    tree[node][0] = min(a, b);
    tree[node][1] = a == tree[node][0] ? tree[node * 2][1] : tree[node * 2 + 1][1];
}
ll solve(int s, int e) {
    auto [minh, idx] = query(s, e);
    
   // cout << "split into idx" << idx << endl;
    if (minh == INT_MAX) return -1;
    ll area = (ll)(e - s + 1) * minh;
    //cout << "e" << e << " s" << s << "area : " << area << endl;
    if (s >= e) return area;
    return max({area, solve(s, idx - 1), solve(idx + 1, e)});
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(1) {
        int n;
        cin >> n;
        if (n == 0) break;
        arr.clear();
        memset(tree, -1, sizeof tree);
        for (int i = 0; i < n; i++) {
            int in;
            cin >> in;
            arr.emplace_back(in);
        }

        init();

        cout << solve(1, arr.size()) << endl;
    }
}