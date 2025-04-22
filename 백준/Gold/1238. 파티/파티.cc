#include <bits/stdc++.h>

using namespace std;

vector<array<int , 2>> graph[1001];
priority_queue<array<int, 2>> pq;
int dist[1001];

int totdist[1001];
int main() {
    int n, m,x;
    cin >> n >> m >> x;

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++) {
        memset(dist, 0x3f, sizeof dist);
        dist[i] = 0;
        bool mod = false;
        if (i == x) {
            mod = true;
        }
        pq.push({0, i});
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();

            int d = -cur[0];
            int c = cur[1];
            if (dist[c] < d) continue;
            
            for (auto &[n, cost]: graph[c]) {
                if (dist[n] > d + cost) {
                    dist[n] = d + cost;
                    pq.push({-dist[n], n});
                }
            }
        }
        if (mod) {
            for (int j = 1; j <= n; j++) {
                if (j == x) continue;
                totdist[j] += dist[j];
            }
        }
        else totdist[i] += dist[x];
    }
    
    int maxval = 0;
    for (int i = 1; i <= n; i++) {
        maxval = max(totdist[i], maxval);
    }
    cout << maxval << endl;
}