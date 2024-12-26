import java.io.*;
import java.util.*;

public class _2164_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        LinkedList<Integer> num = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            num.add(i);
        }

        for (int i = 1; i < N; i++) {
            num.poll();
            num.add(num.poll());
        }

        System.out.println(num.poll());
    }
}