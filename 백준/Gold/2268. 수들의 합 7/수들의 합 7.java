
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static final int sz = 1 << 20;
	static final int treesz = sz << 1;
	static long tree[] = new long[treesz];
	
	static ArrayList<Integer> arr;
	
	static long _query(int l, int r, int node, int s, int e) {
		if (s > r || e < l) return 0;
		if (l <= s && e <= r) return tree[node];
		
		int m = s + e >> 1;
		return _query(l, r, node * 2, s, m) + _query(l, r, node * 2 + 1, m + 1, e);
	}
	static void _update(int idx, int val, int node, int s, int e) {
		if (idx < s || idx > e) return;
		if (s == e && s == idx) {
			tree[node] = (long)val;
			return;
		}
		int m = s + e >> 1;
		_update(idx, val, node * 2, s, m);
		_update(idx, val, node * 2 + 1, m + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	static void _init(int node, int s, int e) {
		if (s == e && s > arr.size()) return; // if e == arr.size(), then this code is eligible
		if (s == e) {
			tree[node] = arr.get(s - 1);
			return;
		}
		int m = s + e >> 1;
		_init(node * 2, s, m);
		_init(node * 2 + 1, m + 1, e);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	static long query(int l, int r) {
		return _query(l, r, 1, 1, sz);
	}
	static void update(int idx, int val) {
		_update(idx, val, 1, 1, sz);
	}
	static void init() {
		_init(1, 1, sz);
	}
	
	public static void main(String[] args ){
		int n, m;
		InputStreamReader is = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(is);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		try {
			String in = br.readLine();
			StringTokenizer st = new StringTokenizer(in);
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			//System.out.println(m);
			for (int k = 0; k < m; k++) {
				int a, b, c;
				String in2 = br.readLine();
				StringTokenizer st2 = new StringTokenizer(in2);
				a = Integer.valueOf(st2.nextToken());
				b = Integer.valueOf(st2.nextToken());
				c = Integer.valueOf(st2.nextToken());
				
				//System.out.println(a + " " +  b + " " +  c);
				if (a == 0) {
					int bb = Math.min(b, c);
					int cc = Math.max(b, c);
					
					bw.write(query(bb, cc) + "\n");
					//System.out.println(query(bb, cc));
					bw.flush();
				}
				else {
					update(b, c);
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		
		
	}
}
