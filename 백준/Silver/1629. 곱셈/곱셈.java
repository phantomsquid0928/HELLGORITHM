import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {

    static long calc(int a, int b, int c) {
        long x;

        if (b == 0) {
            return 1;
        }

        if (b == 1) {
            return a % c;
        }

        if (b % 2 == 0) {
            x = calc(a, b / 2, c);
            return (x * x) % c;
        } else {
            x = calc(a, (b - 1) / 2, c);
            return (x * x * a) % c;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        // System.out.println(calc(A, B, C));

        BigInteger AA = BigInteger.valueOf(A);
        BigInteger BB = BigInteger.valueOf(B);
        BigInteger CC = BigInteger.valueOf(C);

        System.out.println(AA.modPow(BB, CC));
    }
}
