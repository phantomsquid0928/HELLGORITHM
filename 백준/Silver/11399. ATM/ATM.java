import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int n,m;
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		
		int arr[] = new int[n + 1];
		int s[] = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			arr[i] = sc.nextInt();
		}
		
		Arrays.sort(arr);
		
		for (int i = 1; i <= n; i++) {
			s[i] += s[i - 1] + arr[i];
		}
		
		int res = 0;
		for (int i = 1; i <= n; i++) {
//			System.out.println(s[i]);
			res += s[i];
		}
		System.out.println(res);
	}
}
