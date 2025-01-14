#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int stage = 0;
    int vert = bill[1];
    int hori = bill[0];
    sort(wallet.begin(), wallet.end());
    
    cout << wallet[0] << wallet[1] << endl;
    
    while(1) {
        bool check = false;
        if (vert > hori) {
            if (wallet[0] >= hori && wallet[1] >= vert) check = true;
            else {
                vert = vert >> 1;
            }
        }
        else {
            if (wallet[0] >= vert && wallet[1] >= hori) check = true;
            else {
                hori = hori >> 1;
            }
        }
        
        if (check) {
            return stage;
        }
        stage++;
    }
    
    // return answer;
}