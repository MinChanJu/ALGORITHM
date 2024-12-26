import java.io.*;
import java.util.StringTokenizer;

public class _10830_G4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        long B = Long.parseLong(tmp[1]);

        int matrix[][] = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int result[][] = matrixPow(matrix, B);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sb.append(result[i][j]%1000).append(" ");
            }
            sb.append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }

    static int[][] matrixMul(int[][] a, int[][] b) {
        int n = a.length;
        int[][] ret = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += a[i][k] * b[k][j];
                }
                ret[i][j] = (int) (sum % 1000);
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
