import java.io.*;
import java.util.*;

public class _11866_S4 {
public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    String tmp[] = br.readLine().split(" ");
    int N = Integer.parseInt(tmp[0]);
    int K = Integer.parseInt(tmp[1]);

    LinkedList<Integer> num = new LinkedList<>();
    for (int i = 1; i <= N; i++) {
        num.add(i);
    }

    sb.append("<");
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < K; j++) {
            num.add(num.poll());
        }
        sb.append(num.poll());
        if (i != N-1) sb.append(", ");
    }

    sb.append(">");
    System.out.println(sb);
}
}