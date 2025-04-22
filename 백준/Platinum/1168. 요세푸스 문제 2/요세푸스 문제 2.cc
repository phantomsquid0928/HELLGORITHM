#include <bits/stdc++.h>

using namespace std;

constexpr int sz = 1 << 17;
constexpr int treesz = sz << 1;

pair<int, int> tree[treesz];


void update(int idx, int val1, int val2, int node = 1, int s = 1, int e = sz) {
    if (s > idx || e < idx) return;
    if (s == e) {
        tree[node] = {val1, val2};
        return;
    }
    int m = s + e >> 1;
    update(idx, val1, val2, node * 2, s, m);
    update(idx, val1, val2, node * 2 + 1, m + 1, e);
    tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
}
int kth(int k, int node = 1, int s = 1, int e = sz) {
    if (s == e) return tree[node].second;
    int left = tree[node * 2].first;
    int m = s + e >> 1;

    if (k > left) return kth(k - left, node * 2 + 1, m + 1, e);
    else return kth(k, node * 2, s, m);
}
int main() {
    int n, k;
    cin >> n >> k;

    for (int i =1; i <= n; i++) {
        update(i, 1, i);
    }

    int idx = 0;
    cout << "<";
    for (int i = 0; i< n - 1; i++) {
        idx = (idx + k - 1) % (n - i);
        int knum = kth(idx + 1);
        cout << knum << ", ";
        update(knum, 0, 0);

    }
    int knum = kth(1);
    cout << knum << ">";
}