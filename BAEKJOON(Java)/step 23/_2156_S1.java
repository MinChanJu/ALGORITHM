import java.io.*;

public class _2156_S1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int grape[] = new int[N];
        for (int i = 0; i < N; i++) {
            grape[i] = Integer.parseInt(br.readLine());
        }

        if (N == 1) System.out.println(grape[0]);
        else if (N == 2) System.out.println(grape[0] + grape[1]);
        else {
            int dp[] = new int[N];
            dp[0] = grape[0];
            dp[1] = grape[0] + grape[1];
            dp[2] = Math.max(Math.max(grape[0], grape[1]) + grape[2], dp[1]);

            for (int i = 3; i < N; i++) {
                dp[i] = Math.max(Math.max(dp[i-2], dp[i-3]+grape[i-1])+grape[i],dp[i-1]);
            }

            System.out.println(dp[N-1]);
        }
    }
}