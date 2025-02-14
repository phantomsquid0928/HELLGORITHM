import java.io.*;
import java.util.*;

public class Solution {
    static int T;
    static int[] trees;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());

        for (int t = 1; t <= T; t++) {
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            trees = new int[N];
            for (int i = 0; i < N; i++) {
                trees[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(trees);

            int highest = trees[N - 1];
            int one = 0;
            int two = 0;

            for (int i = 0; i < N; i++) {
                one += (highest - trees[i]) % 2;
                two += (highest - trees[i]) / 2;
            }

            int min = Math.min(one, two);

            one -= min;
            two -= min;
            int day = min * 2;

            if (one > 0) {
                day += 2 * one - 1;
            }
            if (two > 0) {
                day += two + 1 + ((two - 1) / 3);
            }

            System.out.printf("#%d %d\n", t, day);
        }
    }
}
