#include <bits/stdc++.h>
#define ll long long
using namespace std;

constexpr int sz = 1 << 17;
constexpr int treesz = sz << 1;

array<ll, 3> tree[treesz];
vector<int> arr;

void init(int node =1 , int s = 1, int e = arr.size()) {
    if (s == e && s > arr.size()) return;
    if (s == e) {
        tree[node] = {arr[s - 1], arr[s - 1], s};
        return;
    }
    int m = s + e >> 1;
    init(node * 2, s, m); init(node * 2 + 1, m + 1, e);
    tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
    tree[node][1] = min(tree[node * 2][1], tree[node * 2 + 1][1]);
    tree[node][2] = tree[node * 2][1] > tree[node * 2 + 1][1] ? tree[node * 2 + 1][2] : tree[node * 2][2];
}
pair<ll, int> query(int l, int r, int mode, int node = 1, int s = 1, int e = arr.size()) {
    if (s > r || e < l) {
        if (mode) return {0, 0};
        else return {100000000, 0};
    }
    if (l <= s && e <= r) {
        if (mode) return {tree[node][0], 0};
        else return {tree[node][1], tree[node][2]};
    }
    int m = s + e >> 1;
    if (mode) {
        auto a = query(l, r, mode, node * 2, s, m);
        auto b = query(l, r, mode, node * 2 + 1, m + 1, e);
        return {a.first + b.first, 0};
    }
    else {
        auto a = query(l, r, mode, node * 2, s, m);
        auto b = query(l, r, mode, node * 2 + 1, m + 1, e);
        return {min(a.first, b.first), a.first > b.first ? b.second : a.second};
    }
}
ll solve(int s = 1, int e = arr.size()) {
   // if (s > e) return -1;
    ll sum = query(s, e, 1).first;

    pair<ll, int> minandidx = query(s, e, 0);
    
    int idx = minandidx.second;

    if (s >= e) {
        return sum * minandidx.first;
    }
    else {
        ll a = solve(s, idx - 1);
        ll b = solve(idx + 1, e);
    
        return max({sum * minandidx.first, a, b}); 
    }
}
int main() {
    int n;
    cin >> n;

    for (int i =0 ;i < n; i++) {
        int in;
        cin >> in;
        arr.emplace_back(in);
    }

    init();

    cout << solve() << endl;
    //cout << tree[1][0] << endl;
}