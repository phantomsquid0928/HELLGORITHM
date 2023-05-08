#include <bits/stdc++.h>

using namespace std;


int stackv[1001];
int stacko[1001];
int dead[1001] = {};
int top = -1;
int topo = -1;
int n;
int cnt = 0;

struct Point {
	int x, y;
	int vx, vy;
	
	Point(){}
	Point(int x1, int y1, int p1 = 0, int q1 = 0): x(x1), y(y1), vx(p1), vy(q1) {}
	
	bool operator<(const Point& o) {
		if (1ll * vy * o.vx != 1ll * vx * o.vy) return 1ll * vy * o.vx < 1ll * vx * o.vy;
		if (y != o.y) return y < o.y;
		return x < o.x;
	}
};

int ccw(const Point& a, const Point& b, const Point& c) {
	long long temp = 1ll * (b.x - a.x) * (c.y - a.y) - 1ll * (b.y - a.y) * (c.x - a.x);
	if (temp < 0) return -1;
	else if (temp == 0) return 0;
	else return 1;
}
vector<Point> vec;
struct Point p;



int main() {
	int answer = 0;
	cin >> n >> p.x >> p.y;
	for (int i = 0;i < n; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back(Point(x, y));
	}
	cnt = 0;
	while(1) {
		memset(stackv, 0, sizeof(stackv));
		top = -1;
		memset(stacko, 0, sizeof(stacko));
		topo = -1;
		sort(vec.begin(), vec.end());
		for (int i = 1;i < vec.size(); i++) {
			vec[i].vx = vec[i].x - vec[0].x;
			vec[i].vy = vec[i].y - vec[0].y;
		}
		sort(vec.begin() + 1, vec.end());
		vector<Point> last_vec = vec;
		
		stackv[0] = 0;
		stackv[1] = 1;
		top = 1;
		int next = 2;
		
		while(next < vec.size()) {
			while(top + 1 >= 2) {
				//cout << top << endl;
				int i, j;
				j = stackv[top];
				top--;
				i = stackv[top];
				//cout << vec[i].x << ","<< vec[i].y << ": " << j << " : " << next << endl;
				if (ccw(vec[i], vec[j], vec[next]) > 0) {
					//cout << vec[i].x << "," << vec[i].y << " : " << vec[j].x << "," << vec[j].y << endl;
					stackv[top + 1] = j;
					top++;
					break;
				}
			}
			stackv[top + 1] = next++;
			top++;
		}
		//cout << "top : " << top << endl;
		
		memcpy(stacko, stackv, sizeof(stackv));
		topo = top;
		int start = stackv[top];
		int first = stackv[top];
		top--;
		int second = stackv[top];
		top--;
		int check = ccw(vec[first], vec[second], p);
		int inner = 1;
		while(top > -1) {
			first = second;
			second = stackv[top];
			top--;
			if (check != ccw(vec[first], vec[second], p)) {
				//cout << 'f' << endl;
				inner = 0;
				break;
			}
		}
		if (check != ccw(vec[second], vec[start], p))
			inner = 0;
		//cout << "inner" << inner << endl;
		if (inner) {
			answer++;
			memset(dead, 0, sizeof(dead));
			cnt = 0;
			for (int i = 0; i<= topo; i++) {
				dead[stacko[i]] = 1;
				//cout << stacko[i] << endl;
			}
			vec.clear();
			for (int i = 0; i < last_vec.size(); i++) {
				if (dead[i] != 1) {
					vec.push_back(last_vec[i]);
				}
			}
		} else {
			break;
		}
		if (vec.size() < 3) break;
			
		
	}
	cout << answer;
	
}