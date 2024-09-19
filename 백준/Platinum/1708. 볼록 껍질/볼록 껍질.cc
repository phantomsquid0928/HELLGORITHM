#include <bits/stdc++.h>

using namespace std;

int arr[1000][1000];
vector<pair<int, int>> pts;
int main() {
    int n;
    cin >> n;
    pair<int, int> minypt = {40002, 40002};
    for (int i = 0 ;i  < n; i++) {
        int a, b;
        cin >> a >> b;
        pts.push_back({b, a});
    }
    // cout << minypt.first << minypt.second << endl;
    auto sorter = [&](pair<int, int> &a, pair<int, int>& b) {
        pair<int, int> voa = {a.first - minypt.first, a.second - minypt.second};
        pair<int, int> vob = {b.first - minypt.first, b.second - minypt.second};
        
        if ((long long)voa.first * (long long)vob.second - (long long)voa.second * (long long)vob.first == 0) {
            if ((long long)voa.first * voa.first + (long long)voa.second * voa.second < (long long)vob.first * vob.first + (long long)vob.second * vob.second) return false;
            return true;
            // false < change
        }
        if ((long long)voa.first * (long long)vob.second - (long long)voa.second * (long long)vob.first < 0) return false;
        return true;
    };
    sort(pts.begin(), pts.end());
    minypt = pts[0];
    sort(pts.begin() + 1, pts.end(), sorter);
    pts.push_back(minypt);
    // cout << endl;
    // for (auto &a : pts) {
    //     cout << a.first << " " << a.second << endl;
    // }

    //vector<pair<int, int>> convex;
     vector<pair<int, int>> convex;
    for (auto &point : pts) {
        while (convex.size() > 1) {
            pair<int, int> p1 = convex[convex.size() - 2];
            pair<int, int> p2 = convex[convex.size() - 1];
            pair<int, int> p3 = point;
            minypt = p1;
            //long long cross_product = (long long)(p2.first - p1.first) * (p3.second - p1.second) - (long long)(p2.second - p1.second) * (p3.first - p1.first);
            if (!sorter(p2, p3)) {
                convex.pop_back();
            } else {
                break;
            }
        }
        convex.push_back(point);
    }

    cout << convex.size() - 1<< endl;
    // for (auto &i : convex) {
    //     cout << i.first << " " << i.second << endl;
    // }
    return 0;
}