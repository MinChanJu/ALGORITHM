import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class _17219_S4 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    String[] input = br.readLine().split(" ");
    int N = Integer.parseInt(input[0]);
    int M = Integer.parseInt(input[1]);

    Map<String, String> notes = new HashMap<>();
    for (int i = 0; i < N; i++) {
      input = br.readLine().split(" ");
      notes.put(input[0], input[1]);
    }

    for (int i = 0; i < M; i++) {
      String site = br.readLine();
      sb.append(notes.get(site)).append("\n");
    }

    bw.write(sb.toString());
    bw.flush();
  }
}
