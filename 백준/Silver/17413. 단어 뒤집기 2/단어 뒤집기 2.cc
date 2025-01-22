#include <bits/stdc++.h>

using namespace std;

vector<char> st;

int main() {
    string s;
    string res = "";
    getline(cin, s);
    int mod =0 ;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '<') {
            mod = 1;
            
            while(st.size()) {
                res += st.back();
                st.pop_back();
            }
            
            res += string(1, c);

            continue;
        }
        if (c == '>') {
            mod = 0;
            res += string(1, c);
            continue;
        }
        if (c == ' ') {
            while(st.size()) {
                res += st.back();
                st.pop_back();
            }
            res += string(1, c);
            continue;
        }
        if (mod == 1) {
            res += string(1, c);
            continue;
        }
        else {
            st.push_back(c);
        }
    }
    while(st.size()) {
        res += st.back();
        st.pop_back();
    }
    cout << res << endl;
}