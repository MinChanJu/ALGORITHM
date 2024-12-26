import java.io.*;

public class _2565_G5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int line[] = new int[501];
        for (int i = 0; i < N; i++) {
            String input[] = br.readLine().split(" ");
            int A = Integer.parseInt(input[0]);
            int B = Integer.parseInt(input[1]);
            line[A] = B;
        }

        int dp[] = new int[501];
        dp[0] = 1;
        for (int i = 1; i < 501; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (line[j] < line[i]) dp[i] = Math.max(dp[j]+1, dp[i]);
            }
        }

        int max = 0;
        for (int i = 0; i < 501; i++) {
            if (max < dp[i]) max = dp[i];
        }

        System.out.println(N-max+1);
    }
}