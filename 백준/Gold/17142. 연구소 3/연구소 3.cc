#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> node;
vector<pair<int, int>> viruses;

pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int visitedo[51][51];

int calc(int simbol, int n, int viruscnt) {
    queue<array<int, 3>> q;
    int visited[51][51];
    memcpy(visited, visitedo, sizeof(visitedo));
    auto nodecpy = node;
    

    for (int i = 0;i < viruscnt; i++) {
        
        if ((simbol >> i) & 1) {
            q.push({viruses[i].first, viruses[i].second, 0});
        }

    }

    int maxstage = 0;
    int curstage = 0;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur[0];
        int y = cur[1];
        int stage = cur[2];
        if (visited[x][y] != 0) continue;
        visited[x][y] = stage + 1;
        maxstage = max(maxstage, stage);
        nodecpy.erase(x * n + y);
        if (nodecpy.empty()) break;
        for (auto &d : dirs) {
            int dx = x + d.first;
            int dy = y + d.second;
            if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
            if (visited[dx][dy] != 0) continue;
            q.push({dx, dy, stage + 1});
        }
    }

   
    if (nodecpy.empty()) return maxstage;
    else return INT_MAX;
    //cout << maxstage << endl;
    //return maxstage;
    
}

int main () {
    int n, m;

    cin >>n >> m;

    int viruscnt = 0;

    for (int i= 0 ; i< n; i++) {
        for (int j = 0;j < n; j++) {
            int t;
            cin >> t;
            if (t == 1) visitedo[i][j] = -1;
            if(t == 2) {
                viruscnt++;
                viruses.push_back({i, j});
            }
            if(t == 0) node.insert({i * n + j, t});
        }
    }
    int res = INT_MAX;

    for (int i = 1; i < pow(2, viruscnt); i++) {
        int cnt = 0;
        bool non = false;
        for (int j = 0; j < viruscnt; j++){
            if ((i >> j) & 1) cnt++;
        }
        if (cnt != m) continue;

        res = min(res, calc(i, n, viruscnt));
    }
    if (res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;
}