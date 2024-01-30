#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<int, int> dp;


ll divcon(ll a, ll b, ll c) {
	if (dp.find(b) != dp.end()) {
		return dp.find(b)->second % c;
	}
	if (b == 0) return 1;
	if (b == 1) return a % c;
	dp.insert({b, divcon(a, (ll)b / 2, c) * divcon(a, b - (ll)(b / 2), c) % c});
	return dp.find(b)->second;
}
int main() {
	ll a, b, c;
	cin >> a>> b >>c;
	cout << divcon(a, b, c) << endl;
}