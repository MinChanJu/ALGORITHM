import java.io.*;
import java.util.*;

public class _4949_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true) {
            String input = br.readLine();
            if (input.equals(".")) break;
            Stack<String> stack = new Stack<>();
            int k = 0;
            for (char ch : input.toCharArray()) {
                if (ch == '(') stack.push(ch+"");
                else if (ch == '[') stack.push(ch+"");
                else if (ch == ')') {
                    if (stack.isEmpty()) {
                        k = 1;
                        break;
                    }
                    else if (stack.peek().equals("(")) stack.pop();
                    else {
                        k = 1;
                        break;
                    }
                }
                else if (ch == ']') {
                    if (stack.isEmpty()) {
                        k = 1;
                        break;
                    }
                    else if (stack.peek().equals("[")) stack.pop();
                    else {
                        k = 1;
                        break;
                    }
                }
            }

            if (k == 1 || !stack.isEmpty()) sb.append("no\n");
            else sb.append("yes\n");
        }

        System.out.print(sb);
    }
}
