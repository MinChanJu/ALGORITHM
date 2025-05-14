import java.io.*;
import java.util.*;

public class _1725_P5 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    List<Integer> histogram = new ArrayList<>();
    for (int i = 0; i < N; i++)
      histogram.add(Integer.parseInt(br.readLine()));

    Stack<Integer> stack = new Stack<>();

    int max = 0;
    for (int i = 0; i < N; i++) {
      while (!stack.isEmpty() && histogram.get(stack.peek()) > histogram.get(i)) {
        int t = stack.pop();
        int s = stack.isEmpty() ? i : i - stack.peek() - 1;
        max = Math.max(max, histogram.get(t) * s);
      }
      stack.push(i);
    }

    while (!stack.isEmpty()) {
      int t = stack.pop();
      int s = stack.isEmpty() ? histogram.size() : histogram.size() - stack.peek() - 1;
      max = Math.max(max, histogram.get(t) * s);
    }

    sb.append(max).append("\n");

    bw.write(sb.toString());
    bw.flush();
  }
}