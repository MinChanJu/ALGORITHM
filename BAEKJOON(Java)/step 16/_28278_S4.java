import java.io.*;
import java.util.*;

public class _28278_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        Stack<Integer> stack = new Stack<>();
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String tmp[] = br.readLine().split(" ");
            if (tmp[0].equals("1")) stack.push(Integer.parseInt(tmp[1]));
            else if (tmp[0].equals("2")) {
                if (stack.isEmpty()) sb.append(-1).append("\n");
                else sb.append(stack.pop()).append("\n");
            } else if (tmp[0].equals("3")) sb.append(stack.size()).append("\n");
            else if (tmp[0].equals("4")) sb.append(stack.isEmpty() ? 1 : 0).append("\n");
            else if (tmp[0].equals("5")) {
                if (stack.isEmpty()) sb.append(-1).append("\n");
                else sb.append(stack.peek()).append("\n");
            }
        }

        System.out.print(sb);
    }
}