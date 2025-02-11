import java.util.*;
import java.io.*;

public class Main {
	static int cnt = 0;
	static char[][] arr;
	static int[][] arr2;

	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };

	static boolean[] dfsV = new boolean[25];
	static boolean[][] bfsV;
	// static ArrayList<int[]> groups = new ArrayList<>();

	public static void dfs(int idx, int start, int[] sel) {
		if (idx == 7) {
			int sCount = 0;
			arr2 = new int[5][5];

			for (int i = 0; i < 7; i++) {
				int x = sel[i] / 5;
				int y = sel[i] % 5;

				arr2[x][y] = 1;

				if (arr[x][y] == 'S') {
					sCount += 1;
				}
			}

			if (sCount >= 4) {
				int x = sel[0] / 5;
				int y = sel[0] % 5;
				bfsV = new boolean[5][5];
				bfs(x, y);

				for (int i = 0; i < 7; i++) {
					int x2 = sel[i] / 5;
					int y2 = sel[i] % 5;

					if (!bfsV[x2][y2]) {
						return;
					}
				}
				cnt += 1;
				// groups.add(sel.clone());
			}
			return;
		}

		for (int i = start; i < 25; i++) {
			if (!dfsV[i]) {
				dfsV[i] = true;
				sel[idx] = i;
				dfs(idx + 1, i + 1, sel);
				dfsV[i] = false;
			}
		}
	}

	public static void bfs(int x, int y) {
		Deque<int[]> queue = new ArrayDeque<>();

		queue.add(new int[] { x, y });
		bfsV[x][y] = true;

		while (!queue.isEmpty()) {
			int[] cur = queue.poll();

			for (int i = 0; i < 4; i++) {
				int nx = cur[0] + dx[i];
				int ny = cur[1] + dy[i];

				if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && !bfsV[nx][ny] && arr2[nx][ny] == 1) {
					queue.add(new int[] { nx, ny });
					bfsV[nx][ny] = true;
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		arr = new char[5][5];

		for (int i = 0; i < 5; i++) {
			arr[i] = br.readLine().toCharArray();
		}

		dfs(0, 0, new int[7]);

		// System.out.println(Arrays.deepToString(arr));
		// System.out.println(groups.size());

		// for (int[] a : groups) {
		// 	System.out.println(Arrays.toString(a));
		// }

		System.out.println(cnt);
	}
}
