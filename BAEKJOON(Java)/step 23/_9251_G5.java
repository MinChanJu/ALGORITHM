import java.io.*;

public class _9251_G5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String A = br.readLine();
        String B = br.readLine();

        int dp[][] = new int[1001][1001];
        for (int i = 0; i < A.length(); i++) {
            for (int j = 0; j < B.length(); j++) {
                if (A.charAt(i) == B.charAt(j)) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = Math.max(dp[i+1][j], dp[i][j+1]);
            }
        }

        System.out.println(dp[A.length()][B.length()]);
    }
}