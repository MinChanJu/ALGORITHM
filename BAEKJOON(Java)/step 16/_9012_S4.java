import java.io.*;
import java.util.*;

public class _9012_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String input = br.readLine();
            Stack<String> stack = new Stack<>();
            int k = 0;
            for (char ch : input.toCharArray()) {
                if (ch == '(') stack.push(ch+"");
                else {
                    if (stack.isEmpty()) {
                        k = 1;
                        break;
                    }
                    else stack.pop();
                }
            }

            if (k == 1 || !stack.isEmpty()) sb.append("NO\n");
            else sb.append("YES\n");
        }

        System.out.print(sb);
    }
}