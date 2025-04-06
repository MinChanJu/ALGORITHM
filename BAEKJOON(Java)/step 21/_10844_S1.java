import java.io.*;

public class _10844_S1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[][] dp = new int[N+1][10];

        for (int i = 1; i < 10; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < 10; j++) {
                if (j == 0) dp[i][j] = dp[i-1][j+1];
                else if (j == 9) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
            }
        }

        int sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += dp[N][j];
            sum %= 1000000000;
        }
        System.out.println(sum);
    }
}