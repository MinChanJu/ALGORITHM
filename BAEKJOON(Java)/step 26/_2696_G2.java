import java.io.*;
import java.util.*;

public class _2696_G2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int T = Integer.parseInt(br.readLine());
    while (T-- > 0) {
      int M = Integer.parseInt(br.readLine());
      List<Integer> S = new ArrayList<>();
      for (int i = 0; i < M/10; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < 10; j++) {
          S.add(Integer.parseInt(st.nextToken()));
        }
      }
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < (M-((M/10)*10)); i++) {
        S.add(Integer.parseInt(st.nextToken()));
      }

      List<Integer> medians = new ArrayList<>();
      List<Integer> sub = new ArrayList<>();
      for (int i = 0; i < M; i++) {
        sub.add(S.get(i));
        if (i%2 == 0) {
          sub.sort(null);
          medians.add(sub.get(i/2));
        }
      }

      sb.append(medians.size()).append("\n");
      for (int i = 0; i < medians.size(); i++) {
        sb.append(medians.get(i));
        if ((i+1)%10 == 0 || i == medians.size()-1) sb.append("\n");
        else sb.append(" ");
      }
    }

    bw.write(sb.toString());
    bw.flush();
  }
}