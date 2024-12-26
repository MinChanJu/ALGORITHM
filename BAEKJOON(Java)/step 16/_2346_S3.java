import java.io.*;
import java.util.*;

public class _2346_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int num[] = new int[N+1];
        for (int i = 1; i <= N; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }

        Deque<Integer> deck = new ArrayDeque<>();

        for (int i = 1; i <= N; i++) {
            deck.addLast(i);
        }

        for (int i = 0; i < N; i++) {
            int A = deck.pollFirst();
            sb.append(A).append(" ");
            if (deck.isEmpty()) break;
            if (num[A] > 0) {
                for (int j = 1; j < num[A]; j++) {
                    deck.addLast(deck.pollFirst());
                }
            } else {
                for (int j = 0; j < -num[A]; j++) {
                    deck.addFirst(deck.pollLast());
                }
            }
        }

        System.out.println(sb);
    }
}