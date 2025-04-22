#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[101];
vector<pair<int, int>> graph2[101];
int indeg[101];
map<int, int> used[101];
set<int> leafs;
queue<int> q;

//
int main() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    for (int i= 0;i < m; i++) {
        int x, y, k;

        cin >> x >> y >> k;
        graph[y].push_back({x, k});
        graph2[x].push_back({y, k});
        indeg[x]++;
    }

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            used[i].insert({i, 1});
        }
    }


    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int num = cur;

        for (auto &[x , k] : graph[num]) {
            for (auto &[e, cnt] : used[num]) {
                if (used[x].count(e)) {
                    used[x][e] += k * cnt;
                }
                else {
                    used[x][e] = k * cnt;
                }
            }
            indeg[x]--;
            if (indeg[x] == 0) q.push(x);
        }
    }

    for (auto &[k, cnt] : used[n]) {
        cout << k << " " << cnt << endl;
    }
}