import java.io.*;
import java.util.*;

public class _12789_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int num[] = new int[N];
        for (int i = 0; i < num.length; i++) num[i] = Integer.parseInt(st.nextToken());

        Stack<Integer> stack = new Stack<>();
        for (int i = N-1; i >= 0; i--) {
            stack.push(num[i]);
        }
        
        Stack<Integer> wait = new Stack<>();

        int cnt = 1;
        while (true) {
            if (!stack.isEmpty() && stack.peek() == cnt) {stack.pop(); cnt++;}
            else if (!wait.isEmpty() && wait.peek() == cnt) {wait.pop(); cnt++;}
            else if (!stack.isEmpty()) wait.push(stack.pop());
            else break;
        }

        if (cnt == N+1) System.out.println("Nice");
        else System.out.println("Sad");
    }
}