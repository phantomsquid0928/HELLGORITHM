import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

class Solution {
	public static class point {
		int x, y, len;
		public point(int x, int y, int len) {
			this.x = x;
			this.y = y;
			this.len = len;
		}
	}
	public static int dirs[][] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	public static void main(String[] args) {
		int t;
		Scanner sc= new Scanner(System.in);
		t = sc.nextInt();
		
		for (int tt= 1; tt <= t; tt++) {
			int n;
			n = sc.nextInt();
			int arr[][] = new int[n][n];
			
			for (int i =0; i < n; i++) {
				for (int j =0 ; j< n; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			
			int res =0 ;
			int roomnum = 100000000;
			
			Queue<point> q = new ArrayDeque<point>();
			
			for (int i=0 ;i < n; i++) {
				for (int j = 0; j< n; j++) {
					int x = i;
					int y = j;
					boolean check = false;
					for (int[] d : dirs) {
						int nx = x + d[0];
						int ny = y + d[1];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (arr[nx][ny] == arr[x][y] + 1) check = true;
					}
					
					if (!check) continue;
					
					q.offer(new point(x, y, 1));
					
					int tempres = 0;
					
					while(!q.isEmpty()) {
						point p = q.poll();
						tempres = Math.max(tempres, p.len);
						for (int[] d : dirs) {
							int nx = p.x + d[0];
							int ny = p.y + d[1];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
							if (arr[nx][ny] == arr[p.x][p.y] + 1) { 
								q.offer(new point(nx, ny, p.len + 1));
							}
						}
					}
					if(tempres > res) {
						res = tempres;
						roomnum = arr[x][y];
					}
					else if (tempres == res) {
						if (roomnum > arr[x][y]) {
							roomnum = arr[x][y];
						}
					}
				}
			}
			System.out.println("#" + tt + " " + roomnum + " " + res);
		}
	}
}
