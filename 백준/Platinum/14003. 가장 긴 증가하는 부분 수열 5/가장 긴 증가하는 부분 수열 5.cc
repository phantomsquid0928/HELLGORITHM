#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int l[1000001];
int p[1000001];

int main() {
    int n;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;

    arr.reserve(n);
    // l.resize(n + 10);

    for (int i = 0;i < n;i ++) {
        int in;
        cin >> in;
        l[i] = 1000000000;
        arr.emplace_back(in);
    }
    l[0] = -1000000000;
    // l.push_back(-1000000000);

    int top = 0;
    int size = 0;
    int maxval = 0;

    for (int i =0 ;i <n ;i++) {
        int idx = lower_bound(l, l + size, arr[i]) - l;
        p[i] = idx;
        if (idx == top || l[idx] > arr[i]) {
  
            l[idx] = arr[i];
            size++;
            top = max(top, idx + 1);
        }
    }



    cout << top << endl;
    int cur = top - 1;
    vector<int> ans;


    // for (int i = 0; i < n;i ++) {
    //     cout << p[i] << " " ;
    // }
    // cout << endl;
    for (int i = n - 1; i >= 0; i--){ 
        if (p[i] == cur) {
            ans.push_back(arr[i]);
            cur--;
        }
    }
    

    for (int i = top - 1; i >= 0; i--) cout << ans[i] << " ";
}