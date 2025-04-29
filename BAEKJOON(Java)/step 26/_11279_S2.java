import java.io.*;
import java.util.*;

public class _11279_S2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    PriorityQueue<Integer> heap = new PriorityQueue<>(Collections.reverseOrder());
    for (int i = 0; i < N; i++) {
      int X = Integer.parseInt(br.readLine());
      if (X != 0)
        heap.add(X);
      else {
        Integer p = heap.poll();
        if (p == null) sb.append("0\n");
        else sb.append(p+"\n");
      }
    }

    bw.write(sb.toString());
    bw.flush();
  }
}
