import java.io.*;

public class _11444_G2 {
    static int p = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long n = Long.parseLong(br.readLine());
        System.out.println(fibo(n));
    }

    static int fibo(long n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int[][] matrix = {{1, 1}, {1, 0}};
        int[][] result = matrixPow(matrix, n - 1);
        return result[0][0];
    }

    static int[][] matrixMul(int[][] a, int[][] b) {
        int n = a.length;
        int[][] ret = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += (long) a[i][k] * b[k][j];
                }
                ret[i][j] = (int) (sum % p);
            }
        }
        return ret;
    }

    static int[][] matrixPow(int[][] a, long b) {
        if (b == 1) return a;
        int ret[][] = matrixPow(a, b / 2);
        if (b % 2 == 0) return matrixMul(ret, ret);
        else return matrixMul(matrixMul(ret, ret), a);
    }
}
