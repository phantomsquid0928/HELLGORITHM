#include <bits/stdc++.h>

using namespace std;


int n, m;
int unionfind[10004] = {};
typedef struct Node {
	int a;
	int b;
	int dist;
}node;

bool comp(node a, node b) {
	return a.dist > b.dist;
}
vector<node> nodes;
int find(int a) {
	if (unionfind[a] == a) return a;
	else {
		return unionfind[a] = find(unionfind[a]);
	}
}
void union_pair(int a, int b) {
	a = find(a);
	b = find(b);
	unionfind[b] = a;
}
int check(int a, int b) {
	return find(a) == find(b) ? 0 : 1;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Node temp;
		temp.a = a;
		temp.b = b;
		temp.dist = c;
		nodes.push_back(temp);
	}

	int start, end;
	cin >> start >> end;
	sort(nodes.begin(), nodes.end(), comp);
//	for (auto t : nodes) {
//		cout << t->a << ":" << t->b << " dist :" << t->dist << endl; 
//	}
	for (int i = 1; i <= n; i++) {
		unionfind[i] = i;
	}
	for (auto t : nodes) {
		if (check(t.a, t.b)) {
			union_pair(t.a, t.b);
		}
		if (!check(start, end)) {
			cout << t.dist;
			break;
		}
	}
	
}