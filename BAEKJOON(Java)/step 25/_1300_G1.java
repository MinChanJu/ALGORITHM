import java.io.*;

public class _1300_G1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    int K = Integer.parseInt(br.readLine());

    int s = 1, e = K;
    while (s <= e) {
      int mid = (s + e) / 2, sum = 0;
      for (int i = 1; i <= N; i++) {
        sum += Math.min(mid / i, N);
      }
      if (sum < K)
        s = mid + 1;
      else
        e = mid - 1;
    }
    sb.append(s + "\n");

    bw.write(sb.toString());
    bw.flush();
  }
}