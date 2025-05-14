#include <bits/stdc++.h>
#define endl '\n'
#define ll long long 
using namespace std;

struct treenode {
    int v, v1, e;
    int l, r;
    treenode () : v(0), v1(0), e(0), l(-1), r(-1) {
    }
    treenode (int v, int v1, int e) : v(v), v1(v1), e(e), l(-1), r(-1) {

    }
};

vector<treenode> tree;
int used = 1;

// pair<int, int> kth(int k, int mod, int node = 0, ll s = 0, ll e = 2*1e18) { //kth cnt, nat exists
//     if (node == -1) return {0, 0};
//     if (s == e) {
//         if (mod) return {tree[node].idx, tree[node].e};
//         else return {tree[node].idx, tree[node].e1};
//     }
//     int m = s + e >> 1;
//     if (tree[node].l == -1) return kth(k, mod, tree[node].r, m + 1, e);
//     else {
//         if (mod) {
//             if (tree[tree[node].l].v < k) return kth(tree[tree[node].l].v - k, mod, tree[node].r, m + 1, e);
//             else return kth(k, mod, tree[node].l, s, m);
//         }
//         else {
//             if (tree[tree[node].l].v1 < k) return kth(tree[tree[node].l].v1 - k, mod, tree[node].r, m + 1, e);
//             else return kth(k, mod, tree[node].l, s, m);
//         }
//     }
// }

pair<int, int> query(ll l, ll r, int mod, int node= 0, ll s=0, ll e= 2*1e18) {
    // cout << s << " " << e << endl;
    if (node == -1) return {0, 0};
    if (s > r || e < l) return {0, 0};
    if (l <= s && e <= r) {
        if (mod) return {tree[node].v, tree[node].e};
        else return {tree[node].v1, tree[node].e};
    }
    ll m = s + e >> 1;
    auto a = tree[node].l != -1 ? query(l, r, mod, tree[node].l, s, m) : make_pair(0, 0);
    auto b = tree[node].r != -1 ? query(l, r, mod, tree[node].r, m + 1, e) : make_pair(0, 0);

    return {a.first + b.first, a.second | b.second};
}

void update(ll idx, ll val, int ex, int mod, int node = 0, ll s = 0, ll e = 2 * 1e18) {
    if (s > idx || e < idx) return;
    if (s == e) {
        if (mod) { //mod = 1 -> inc func mod = 0 -> decr func
            tree[node].v += val;
            tree[node].e |= ex;   // 1 : natural, 2 : rational
        }
        else {
            tree[node].v1 += val;
            tree[node].e |= ex;
        }
        return;
    }
    ll m = s + e >> 1;
    if (idx < m + 1) {
        if (tree[node].l == -1) {
            treenode newnode;
            tree.emplace_back(newnode);
            tree[node].l = used++;
        }
        update(idx, val, ex, mod, tree[node].l, s, m);
    }
    else {
        if (tree[node].r == -1) {
            treenode newnode;
            tree.emplace_back(newnode);
            tree[node].r = used++;
        }
        update(idx, val, ex, mod, tree[node].r, m + 1, e);
    }
    array<int, 3> a = {0, 0, 0};
    array<int, 3> b = {0, 0, 0};
    if (tree[node].l != -1) {
        treenode &t = tree[tree[node].l];
        a = {t.v, t.v1, t.e};
    }
    if (tree[node].r != -1) {  
        treenode &t = tree[tree[node].r];
        b = {t.v, t.v1, t.e};
    }  

    tree[node].v = a[0] + b[0];
    tree[node].v1 = a[1] + b[1];
    tree[node].e = a[2] | b[2];
    // cout << "up  ; " << tree[node].v << " " << tree[node].v1 << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int q;
    tree.emplace_back(treenode());

    cin >> q;
    int busted = 0;
    int minuscnt = 0;

    // if (-c / b < 0) modi = -1;
    // ll idx = (ll)floor(-c / b) + (ll)1e18 + modi;
    // cout << -4 % -2 << endl;

    unordered_set<ll> natu;
    while(q--) {
        ll a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            if (b == 0) {
                if (c == 0) {
                    busted = 1;
                    continue;
                }
                if (c < 0) minuscnt++;
            }
            else if (b > 0) { //mod 1 : inc 
                int mod = 1;
                if (c % b == 0) { //ex 1 : natu
                    ll idx = -c / b + (ll)1e18;

                    natu.insert(idx);
                    int ex = 1;
                    // cout << "update1 " << floor(-c / b) << " " << idx << endl;
                    update(idx, 1, ex, mod);
                }
                else {
                    ll modi = 0;
                    if ((-c < 0 && b > 0) || (-c > 0 && b < 0)) modi = -1;
                    ll idx = -c / b + (ll)1e18 + modi;
                    int ex = 2;
                    // cout << "update2 " << floor(-c / b) + modi << " " << idx << endl;
                    update(idx, 1, ex, mod);
                }
            }
            else { //mod 0 decr
                int mod = 0;
                if (c % b == 0) { //ex 1
                    ll idx = -c / b + (ll)1e18;

                    natu.insert(idx);
                    int ex = 1;
                    // cout << "update3 " << floor(-c / b) << " " << idx << endl;
                    update(idx, 1, ex, mod);
                }
                else { // ex 2
                    ll modi = 0;
                    if ((-c < 0 && b > 0) || (-c > 0 && b < 0)) modi = -1;
                    ll idx = -c / b + (ll)1e18 + modi;
                    int ex = 2;
                    // cout << "update4 " << floor(-c / b) + modi << " " << idx << endl;
                    update(idx, 1, ex, mod);
                }
            }
        }
        else {
            cin >> b;
            // unordered_map cur = tree[1];
            int res1 = 0;
            int res2 = 0;
            if (busted) cout << 0 << endl;
            else {
                if (natu.count(b + (ll)1e18)) {
                    cout << "0" << endl;
                    continue;
                }
                auto [res1, exists1] = query(0, b + (ll)1e18 - 1, 0); //dec
                auto [res2, exists2] = query(b + (ll)1e18, (ll)2*1e18, 1); //inc
                // cout << "FF1" << "0 ~ " << b + (ll)1e18 - 1<< endl;
                // cout << "ff2" << b+ (ll)1e18<< " ~ " << 2*1e18 <<  endl;
                // cout <<"FF" << res1 << " " << exists1 << " " << res2 << " " << exists2<< endl;
                // if (exists1 & 1 != 0 || exists2 & 1 != 0) {
                //     cout << 0 << endl;
                //     continue;
                // }
                
                int res = res1 + res2 + minuscnt;
                if (res % 2 == 1) {
                    cout << "-" << endl;
                }
                else cout << "+" << endl;
            }
        }
        

        // for (auto &a : tree) {
        //     cout << a.v << " " << a.e << " " << a.v1 << " " << a.e1 << endl;
        // }
    }
}