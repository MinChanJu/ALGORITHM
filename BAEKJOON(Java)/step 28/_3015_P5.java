import java.io.*;
import java.util.*;

public class _3015_P5 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine()), cnt = 0;
    List<Integer> heights = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      heights.add(Integer.parseInt(br.readLine()));
    }

    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        int A = heights.get(i), B = heights.get(j);
        boolean pos = true;
        for (int k = i+1; k < j; k++) {
          int C = heights.get(k);
          if (A < C || B < C) {
            pos = false;
            break;
          }
        }
        if (pos) cnt++;
      }
    }

    sb.append(cnt + "\n");

    bw.write(sb.toString());
    bw.flush();
  }
}