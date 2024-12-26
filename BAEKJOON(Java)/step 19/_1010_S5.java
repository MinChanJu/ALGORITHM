import java.io.*;
import java.math.*;

public class _1010_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < T; tc++) {
            String tmp[] = br.readLine().split(" ");
            int N = Integer.parseInt(tmp[0]);
            int M = Integer.parseInt(tmp[1]);
            System.out.println(combi(M, N));
        }
    }

    static BigInteger combi(int n, int k) {
        BigInteger result = BigInteger.ONE;
        for (int i = n; i > n-k; i--) result = result.multiply(BigInteger.valueOf(i));
        for (int i = 2; i <= k; i++) result = result.divide(BigInteger.valueOf(i));
        return result;
    }
}