#include <bits/stdc++.h>


using namespace std;

int arr[100][100];
int dist[100][100][2];
int visited[100][100];

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int res = 0;
void dfs(int x, int y, int curdist, int used, int usedval, int n, int k) {
    res = max(res, curdist);
    // if (curdist == 6) {

    //     for (int i = 0;i < n; i++) {
    //         for (int j =0 ; j < n; j++) {
    //             cout << visited[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    // cout << x << " " << y << " " << curdist << " " << used << " " << usedval << endl;
    for (auto d : dirs) {
        int nx = x + d[0];
        int ny = y + d[1];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (usedval != -100) {
            // if (curdist + 1 <= dist[nx][ny][used]) continue;
            if (arr[nx][ny] >= usedval) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            dfs(nx, ny, curdist + 1, used, -100, n, k);
            visited[nx][ny] = 0;
            continue;
        }
        if (arr[nx][ny] >= arr[x][y]) {
            if (used) continue;
            // if (curdist + 1 <= dist[nx][ny][1]) continue;
            if (arr[nx][ny] - k >= arr[x][y]) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            dist[nx][ny][1] = curdist + 1;
            dfs(nx, ny, curdist + 1, 1, arr[x][y] - 1, n, k);
            visited[nx][ny] = 0;
        }
        else {
            // if (curdist + 1 <= dist[nx][ny][used]) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            dist[nx][ny][used] = curdist + 1;
            dfs(nx, ny, curdist + 1, used, -100, n, k);
            visited[nx][ny] = 0;
        }
    }
}
int main() {
    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n, k;
        cin >> n >> k;
        int maxval = 0;
        res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j<n; j++) {
                cin >> arr[i][j];
                maxval = max(arr[i][j], maxval);
            }
        }
        
        for (int i = 0; i< n; i ++) {
            for (int j = 0; j< n; j++) {
                if (arr[i][j] != maxval) continue;

                memset(dist, 0xf3, sizeof dist);
                memset(visited, 0, sizeof visited);

                dist[i][j][0] = 1;
                visited[i][j] = 1;
                dfs(i, j, 1, 0, -100, n, k);
            }
        }

        cout << "#" << tt << " " << res << endl;
    }
    
}