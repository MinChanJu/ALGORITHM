import java.io.*;
import java.util.StringTokenizer;

public class _1932_S1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int num[][] = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j <= i; j++) {
                num[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) num[i][j] += num[i-1][j];
                else if (j == i) num[i][j] += num[i-1][j-1];
                else num[i][j] += Math.max(num[i-1][j-1], num[i-1][j]);
            }
        }

        int max = num[N-1][0];
        for (int i = 1; i < N; i++) {
            if (max < num[N-1][i]) max = num[N-1][i];
        }

        System.out.println(max);
    }
}