import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		int t = 10;
		Scanner sc = new Scanner(System.in);
		for (int tt = 1; tt <= t; tt++) {
			sc.nextInt();
			
			int arr[] = new int[8];
			for (int i =0 ;i < 8; i++) {
				arr[i] = sc.nextInt();
				
			}
			Queue<Integer> q = new LinkedList<Integer>();
			int mina = 1000000000;
			for (int i=0; i< 8; i++) {
				int a = arr[i] / 40;
				mina = Math.min(a,  mina);
			}
			
			for (int i = 0;i  < 8; i++) {
				arr[i] = arr[i] - 15 * mina;
				q.offer(arr[i]);
			}
			
			int k = 0;
			while(!q.isEmpty()) {
				int t1 = q.poll();
				k = k % 5 + 1;
				t1 -= k;
				if (t1 <= 0) break;
				q.offer(t1);
			}
			
			System.out.print("#" + tt + " ");
			while(!q.isEmpty()) {
				System.out.print(q.poll() + " ");
			}
			System.out.println(0);
		}
	}
}
