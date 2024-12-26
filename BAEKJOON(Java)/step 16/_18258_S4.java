import java.io.*;
import java.util.*;;

public class _18258_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        LinkedList<Integer> queue = new LinkedList<>();
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String tmp[] = br.readLine().split(" ");
            if (tmp[0].equals("push")) queue.offer(Integer.parseInt(tmp[1]));
            else if (tmp[0].equals("pop")) sb.append(queue.isEmpty() ? -1 : queue.poll()).append("\n");
            else if (tmp[0].equals("size")) sb.append(queue.size()).append("\n");
            else if (tmp[0].equals("empty")) sb.append(queue.isEmpty() ? 1 : 0).append("\n");
            else if (tmp[0].equals("front")) sb.append(queue.isEmpty() ? -1 : queue.peek()).append("\n");
            else if (tmp[0].equals("back")) sb.append(queue.isEmpty() ? -1 : queue.getLast()).append("\n");
        }

        System.out.print(sb);
    }
}