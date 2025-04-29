import java.io.*;

public class _1003_S3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int[] fibo = new int[42];
    fibo[0] = 1;
    fibo[1] = 0;
    for (int i = 2; i <= 41; i++) {
      fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int T = Integer.parseInt(br.readLine());
    for (int i = 0; i < T; i++) {
      int N = Integer.parseInt(br.readLine());
      sb.append(fibo[N] + " "+ fibo[N+1]+"\n");
    }

    bw.write(sb.toString());
    bw.flush();
  }
}
