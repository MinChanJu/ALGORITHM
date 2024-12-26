import java.io.*;
import java.util.*;

public class _28279_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        LinkedList<Integer> deck = new LinkedList<>();
        int N = Integer.parseInt(br.readLine());
        for (int p = 0; p < N; p++) {
            String tmp[] = br.readLine().split(" ");
            if (tmp[0].equals("1")) deck.addFirst(Integer.parseInt(tmp[1]));
            else if (tmp[0].equals("2")) deck.addLast(Integer.parseInt(tmp[1]));
            else if (tmp[0].equals("3")) sb.append(deck.isEmpty() ? -1 : deck.pollFirst()).append("\n");
            else if (tmp[0].equals("4")) sb.append(deck.isEmpty() ? -1 : deck.pollLast()).append("\n");
            else if (tmp[0].equals("5")) sb.append(deck.size()).append("\n");
            else if (tmp[0].equals("6")) sb.append(deck.isEmpty() ? 1 : 0).append("\n");
            else if (tmp[0].equals("7")) sb.append(deck.isEmpty() ? -1 : deck.peekFirst()).append("\n");
            else if (tmp[0].equals("8")) sb.append(deck.isEmpty() ? -1 : deck.peekLast()).append("\n");
        }

        System.out.print(sb);
    }
}