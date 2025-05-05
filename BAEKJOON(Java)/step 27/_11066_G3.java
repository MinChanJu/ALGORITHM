import java.io.*;
import java.util.*;

public class _11066_G3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int T = Integer.parseInt(br.readLine());
    while (T-- > 0) {
      int K = Integer.parseInt(br.readLine());
      StringTokenizer st = new StringTokenizer(br.readLine());
      int[] pages = new int[K];
      for (int i = 0; i < K; i++) {
        pages[i] = Integer.parseInt(st.nextToken());
      }

      int[] prefix_sum = new int[K + 1];
      prefix_sum[0] = 0;
      for (int i = 0; i < K; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + pages[i];
      }

      int[][] dp = new int[K][K];
      for (int diagonal = 1; diagonal < K; diagonal++) {
        for (int i = 0; i < K - diagonal; i++) {
          int j = i + diagonal;
          int min = dp[i][i] + dp[i + 1][j];
          for (int k = i + 1; k < j; k++) {
            min = Math.min(min, dp[i][k] + dp[k + 1][j]);
          }
          dp[i][j] = min + prefix_sum[j + 1] - prefix_sum[i];
        }
      }

      sb.append(dp[0][K - 1]).append("\n");
    }

    bw.write(sb.toString());
    bw.flush();
  }
}