#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<int, array<ll, 4>> mp;
void matmul(ll a[2][2], ll b[2][2], ll c[2][2]) {
    for (int k =0 ; k < 2; k++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j< 2; j++) {
                c[i][j] = (c[i][j] + ((a[i][k] * b[k][j]) % 1'000'000'007)) % 1'000'000'007;
            }
        }
    }
}
void solve(ll size, ll res[2][2]) {
    if (mp.count(size)) {
        array<ll, 4> mem = mp[size];
        res[0][0] = mem[0];
        res[0][1] = mem[1];
        res[1][0] = mem[2];
        res[1][1] = mem[3];
        return;
    }
    if (size == 1) {
        res[0][0] = 1;
        res[0][1] = 1;
        res[1][0] = 1;
        res[1][1] = 0;
        return;
    }
    

    if (size == 2) {
        ll res1[2][2] = {{1, 1}, {1, 0}};
        ll res2[2][2] = {{1, 1}, {1, 0}};
        return matmul(res1, res2, res);
    }

    ll res1[2][2] = {};
    ll res2[2][2] = {};

    solve(size / 2, res1);
    solve(size - size/ 2, res2);

    matmul(res1, res2, res);

    mp[size] = {res[0][0], res[0][1], res[1][0], res[1][1]};
    return;
}
int main() {
    ll n;
    cin >> n;

    ll res[2][2] = {};

    // int res1[2][2] = {{1, 1}, {1, 0}};
    // int res2[2][2] = {{1, 1}, {1, 0}};
    // matmul(res1, res2, res);
    // cout << res[0][0] << endl;
    solve(n, res);



    cout << res[1][0] << endl;
}