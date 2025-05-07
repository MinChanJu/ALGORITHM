import java.io.*;
import java.util.*;

public class _2293_G4 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    String[] input = br.readLine().split(" ");
    int N = Integer.parseInt(input[0]);
    int K = Integer.parseInt(input[1]);

    List<Integer> coins = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      coins.add(Integer.parseInt(br.readLine()));
    }

    int[] dp = new int[K + 1];
    dp[0] = 1;
    for (Integer coin : coins) {
      for (int i = coin; i <= K; i++) {
        dp[i] += dp[i - coin];
      }
    }

    sb.append(dp[K]).append("\n");

    bw.write(sb.toString());
    bw.flush();
  }
}