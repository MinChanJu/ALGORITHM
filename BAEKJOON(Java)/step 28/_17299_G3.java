import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class _17299_G3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    List<Integer> A = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
    int[] count = new int[1000000];
    for (int i = 0; i < N; i++) {
      count[A.get(i)-1]++;
    }

    Stack<Integer> stack = new Stack<>();
    int[] result = new int[N];

    for (int i = 0; i < N; i++) {
      if (stack.isEmpty()) {
        stack.push(i);
      } else {
        while (!stack.isEmpty() && count[A.get(i)-1] > count[A.get(stack.peek())-1]) {
          int j = stack.pop();
          result[j] = A.get(i);
        }
        stack.push(i);
      }
    }

    while (!stack.isEmpty()) {
      int j = stack.pop();
      result[j] = -1;
    }

    for (int i = 0; i < N; i++) {
      sb.append(result[i]);
      if (i == N - 1)
        sb.append("\n");
      else
        sb.append(" ");
    }

    bw.write(sb.toString());
    bw.flush();
  }
}