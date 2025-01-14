#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    
    sort(mats.begin(), mats.end(), greater<>());
    
    for (auto i : mats) {
        cout << i << endl;
    }
    
    int c = park.size();
    int r = park[0].size();
    
    for (auto size : mats) {
        for (int i =0 ;i < c; i++) {
            for (int j = 0;j < r; j++) {
                bool found = true;
                for (int k = 0; k < size; k++) {
                    if (!found) break;
                    for (int t = 0; t < size; t++) {
                        int dx = i + k;
                        int dy = j + t;
                        if (dx < 0 || dy < 0 || dx >= c || dy >= r) {
                            found = false;
                            break;
                        }
                        if (park[dx][dy][0] != '-') {
                            found = false;
                            break;
                        }
                    }
                }
                if (found) {
                    cout << i << j << endl;
                    return size;
                }
            }
        }
    }
    return -1;
    // return answer;
}