#include <bits/stdc++.h>

using namespace std;

deque<array<int, 2>> q;
int dp[100001];
int main() {
    int a, b;
    cin >> a >> b;
    memset(dp, 0x3f, sizeof dp);
    dp[a] = 1;
    q.push_back({a, 0});
    int res = 0;
    while(!q.empty()) {
        auto [loc, time] = q.front(); q.pop_front();
        if (dp[loc] <= time) continue;
        dp[loc] = time;
        if (loc == b) {
            res = time;
            break;
        }
        if (2 * loc <= 100000) q.push_front({2 * loc, time});
        if (loc - 1 >= 0) q.push_back({loc - 1, time + 1});
        if (loc + 1 <= 100000) q.push_back({loc + 1, time + 1});
    }
    cout << res << endl;
}