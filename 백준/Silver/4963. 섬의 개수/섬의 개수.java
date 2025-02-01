import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static class point {
		int x, y;
		point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static int dirs[][] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<point> q = new LinkedList<point>();
		while(true) {
			int n, m;
			m = sc.nextInt();
			n = sc.nextInt();
			
			if (n == 0 && m == 0) break;
			
			int arr[][] = new int[n][m];
			
			for (int i = 0;i <n; i++) {
				for (int j = 0; j < m; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			int visited[][] = new int[n][m];
			int groupcnt = 0;
			for (int i = 0; i< n ;i++) {
				for (int j = 0; j<m; j++) { 
					if (visited[i][j] > 0) continue;
					if (arr[i][j] == 0) continue;
					
					groupcnt++;
					q.add(new point(i, j));
					
					while(!q.isEmpty()) {
						point cur = q.peek();
						q.poll();
						
						if (visited[cur.x][cur.y] > 0) continue;
						
						visited[cur.x][cur.y] = groupcnt;
						
						for (int[] dir : dirs) {
							int nx = cur.x + dir[0];
							int ny = cur.y + dir[1];
							
							if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
							if (visited[nx][ny] > 0) continue;
							if (arr[nx][ny] == 0) continue;
							
							q.add(new point(nx, ny));
						}
					}
				}
			}
			
			System.out.println(groupcnt);
		}
	}
}
