#include <bits/stdc++.h>

using namespace std;
 

int main() {
    string s;
    cin >> s;

    int cnt= 0 ;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'c') {
            if (i + 1 < s.length()) {
                if (s[i + 1] == '=' || s[i + 1] == '-') {
                    continue;
                }
            }
        }
        if (c == 'd') {
            if (i + 1 < s.length()) {
                if (s[i + 1] == '-') continue;
            }
            if (i + 2 < s.length()) {
                if (s[i + 1] == 'z' && s[i + 2] == '=') continue;
            }
        }
        if (c == 'l') {
            if (i + 1 < s.length()) {
                if (s[i + 1] == 'j') continue;
            }
        }
        if (c == 'n') {
            if (i + 1 < s.length()) {
                if (s[i + 1] == 'j') continue;
            }
        }
        if (c == 's') {
            if (i + 1 < s.length()) {
                if (s[i + 1] == '=') continue;
            }
        }
        if (c == 'z') {
            if (i + 1 < s.length()) {
                if (s[i + 1] == '=') continue;
            }
        }
        cnt++;
    }

    cout << cnt << endl;
}