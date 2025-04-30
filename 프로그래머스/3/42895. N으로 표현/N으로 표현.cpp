#include <bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    int n = N;
    
    unordered_map<int, int> dp; // dp[n] = n 을 만들기 위한 연산횟수
    dp.insert({0, 0});
    
    vector<pair<int, int>> ins;
    int val = 0;
    for (int j = 1; j <= 8; j++) {
        val = val * 10 + n;
        dp.insert({val, j});
    }
    for (int j = 1; j <= 8; j++) {
        for (auto &[num, cnt] : dp) {
            // if (cnt != j) continue;
            for (auto &[num1, cnt1] : dp) {
                int next2 = -1;
                int next = num * num1;
                if (num1 != 0) next2 = num / num1;
                int next3 = num + num1;
                int next4 = num - num1;
                // int next5 = num * 10 + num1;
                if (cnt + cnt1 < 9) ins.emplace_back(next, cnt + cnt1);
                if (num1 != 0 && cnt + cnt1 < 9) ins.emplace_back(next2, cnt + cnt1);
                if (cnt + cnt1 < 9)ins.emplace_back(next3, cnt + cnt1);
                if (next4 != 0 && cnt + cnt1 < 9)ins.emplace_back(next4, cnt + cnt1);
            } 
        }
        for (auto &[k, v] : ins) {
            if (dp.count(k)) {
                dp[k] = min(dp[k], v);
            }
            else {
                dp[k] = v;
            }
        }
    }
    if (!dp.count(number)) answer = -1;
    else answer = dp[number];
    
    return answer;
}