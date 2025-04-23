import java.io.*;
import java.util.*;

public class _2805_S2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;

    st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    List<Integer> tree = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      tree.add(Integer.parseInt(st.nextToken()));
    }

    int s = 0, e = Collections.max(tree);
    while (s <= e) {
      int mid = (s + e) / 2;
      Long sum = tree.stream().mapToLong(i -> Math.max(0, i - mid)).sum();

      if (sum == M) {
        e = mid;
        break;
      }
      if (sum > M)
        s = mid + 1;
      else
        e = mid - 1;
    }

    sb.append(e).append('\n');
    bw.write(sb.toString());
    bw.flush();
  }
}