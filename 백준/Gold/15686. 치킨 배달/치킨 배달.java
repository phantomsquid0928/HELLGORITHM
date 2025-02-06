import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	
	static class point {
		int x, y;
		int status;
		int alive;
		public point(int x, int y, int status) {
			this.x = x;
			this.y = y;
			this.status = status;
		}
		public void setalive(int alive) {
			this.alive = alive;
		}
	}
	public static HashMap<Integer, point> chickens = new HashMap<>();
	public static ArrayList<point> houses = new ArrayList<point>();
	public static void main(String [] args) {
		
		int n, m;
		
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		m = sc.nextInt();
		
		
		
		int chickencnt = 0;
		for (int i= 0;i < n; i++) {
			for (int j = 0; j < n; j++) {
				int in = sc.nextInt();
				
				point p = new point(i, j, in);
				if (p.status == 1) {
					houses.add(p);
				}
				if (p.status == 2) {
					chickens.put(chickencnt++, p);
				}
			}
		}
		
		int totalmin = 1000000000;
		for (int i = 1; i < (1 << chickencnt); i++) {//i is sel
			int cnt= 0;
			for (int j = 0; j < chickencnt; j++) {
				chickens.get(j).setalive(0);
				if ((i & (1 << j)) == 0) continue;
				chickens.get(j).setalive(1);//not to kill
				cnt++;
			}
			
			if (cnt > m) continue;
			
//			for (int j= 0; j< chickencnt; j++) {
//				System.out.print(chickens.get(j).alive);
//			}
//			System.out.println();
			
			
			int sum = 0;
			for (point house : houses) {
				int mindist = 100000000;
				int x = house.x;
				int y = house.y;
				for (Entry<Integer, point> chicken : chickens.entrySet()) {
					
					point cloc = chicken.getValue();
					if (cloc.alive == 0) continue;
					mindist = Math.min(mindist, Math.abs(x - cloc.x) + Math.abs(y - cloc.y));
				}
				sum += mindist;
				
			}
			
			totalmin = Math.min(sum, totalmin);
			
			
		}
		
		System.out.println(totalmin);
	}
}
