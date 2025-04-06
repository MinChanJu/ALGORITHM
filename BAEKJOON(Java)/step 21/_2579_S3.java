import java.io.*;

public class _2579_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int num[] = new int[N];
        for (int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(br.readLine());
        }

        int dp[] = new int[N];
        dp[0] = num[0];
        if (N >= 2) dp[1] = num[0] + num[1];
        if (N >= 3) dp[2] = Math.max(num[0], num[1]) + num[2];

        for (int i = 3; i < N; i++) {
            dp[i] = Math.max(dp[i-2], dp[i-3]+num[i-1]) + num[i];
        }

        System.out.println(dp[N-1]);
    }
}