import java.io.*;
import java.util.*;

public class _24511_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        
        int queuestack[] = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            queuestack[i] = Integer.parseInt(st.nextToken());
        }

        int data[] = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            data[i] = Integer.parseInt(st.nextToken());
        }

        Deque<Integer> ls = new ArrayDeque<>();
        for (int i = 0; i < N; i++) {
            if (queuestack[i] == 0) ls.addLast(data[i]);
        }

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            int A = Integer.parseInt(st.nextToken());
            ls.addFirst(A);
            sb.append(ls.pollLast()).append(" ");
        }
    
        System.out.println(sb);
    }
}