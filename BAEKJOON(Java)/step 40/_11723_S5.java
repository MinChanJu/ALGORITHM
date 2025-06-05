import java.io.*;
import java.util.*;

public class _11723_S5 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int M = Integer.parseInt(br.readLine());

    Set<Integer> S = new HashSet<>();
    for (int i = 0; i < M; i++) {
      String[] input = br.readLine().split(" ");
      if (input[0].equals("add")) {
        int x = Integer.parseInt(input[1]);
        S.add(x);
      } else if (input[0].equals("remove")) {
        int x = Integer.parseInt(input[1]);
        S.remove(x);
      } else if (input[0].equals("check")) {
        int x = Integer.parseInt(input[1]);
        sb.append(S.contains(x) ? 1 : 0).append("\n");
      } else if (input[0].equals("toggle")) {
        int x = Integer.parseInt(input[1]);
        if (S.contains(x))
          S.remove(x);
        else
          S.add(x);
      } else if (input[0].equals("all")) {
        S = new HashSet<>();
        for (int s = 1; s <= 20; s++) {
          S.add(s);
        }
      } else if (input[0].equals("empty")) {
        S = new HashSet<>();
      }
    }

    bw.write(sb.toString());
    bw.flush();
  }
}
