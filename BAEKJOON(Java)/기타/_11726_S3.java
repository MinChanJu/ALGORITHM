import java.io.*;

public class _11726_S3 {
  static int p = 10007;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    int[] dp = new int[N + 2];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % p;
    }

    sb.append(dp[N] + "\n");

    bw.write(sb.toString());
    bw.flush();
  }
}
