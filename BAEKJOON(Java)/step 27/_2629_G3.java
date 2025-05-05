import java.io.*;
import java.util.*;

public class _2629_G3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;

    int N = Integer.parseInt(br.readLine());
    List<Integer> weights = new ArrayList<>();
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < N; i++) {
      weights.add(Integer.parseInt(st.nextToken()));
    }

    int M = Integer.parseInt(br.readLine());
    List<Integer> checkers = new ArrayList<>();
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < M; i++) {
      checkers.add(Integer.parseInt(st.nextToken()));
    }

    Map<Integer, Boolean> possible = new HashMap<>();
    for (Integer w : weights) {
      List<Integer> ls = new ArrayList<>();
      for (Integer key : possible.keySet()) {
        ls.add(w + key);
        ls.add(w - key);
      }
      for (Integer key : ls) {
        possible.put(key, true);
      }
      possible.put(w, true);
    }

    for (Integer checker : checkers) {
      if (possible.getOrDefault(checker, false))
        sb.append("Y").append(" ");
      else
        sb.append("N").append(" ");
    }
    sb.append("\n");

    bw.write(sb.toString());
    bw.flush();
  }
}