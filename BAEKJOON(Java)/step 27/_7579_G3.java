import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class _7579_G3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();
    StringTokenizer st;

    st = new StringTokenizer(br.readLine());
    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    List<Integer> memories = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt)
        .collect(Collectors.toList());

    List<Integer> costs = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt)
        .collect(Collectors.toList());

    List<int[]> dp = new ArrayList<>();
    int need_cost = 0;

    while (true) {
      dp.add(new int[N + 1]);
      for (int i = 0; i < N; i++) {
        if (costs.get(i) <= need_cost) {
          dp.get(need_cost)[i + 1] = Math.max(dp.get(need_cost - costs.get(i))[i] + memories.get(i),
              dp.get(need_cost)[i]);
        } else {
          dp.get(need_cost)[i + 1] = dp.get(need_cost)[i];
        }
      }

      if (Arrays.stream(dp.get(need_cost)).max().getAsInt() >= M)
        break;
      need_cost++;
    }

    sb.append(need_cost).append("\n");

    bw.write(sb.toString());
    bw.flush();
  }
}