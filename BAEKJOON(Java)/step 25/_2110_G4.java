import java.io.*;
import java.util.*;

public class _2110_G4 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    String[] input = br.readLine().split(" ");
    int N = Integer.parseInt(input[0]);
    int C = Integer.parseInt(input[1]);

    List<Integer> homes = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      homes.add(Integer.parseInt(br.readLine()));
    }
    homes.sort(null);

    int s = 0, e = homes.get(N-1);
    while (s <= e) {
      int mid = (s + e) / 2;
      int cnt = 1;
      int last = homes.get(0);
      for (int i = 1; i < N; i++) {
        if (last + mid <= homes.get(i)) {
          last = homes.get(i);
          cnt++;
        }
      }
      if (cnt < C) {
        e = mid - 1;
      } else if (cnt >= C) {
        s = mid + 1;
      }
    }

    sb.append(e).append('\n');

    bw.write(sb.toString());
    bw.flush();
  }
}