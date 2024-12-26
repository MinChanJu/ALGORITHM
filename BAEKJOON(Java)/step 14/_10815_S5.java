import java.io.*;
import java.util.*;

public class _10815_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Map<Integer, Integer> IN = new HashMap<>();
        for (int i = 0; i < N; i++) {
            IN.put(Integer.parseInt(st.nextToken()), 1);
        }

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            if (IN.containsKey(Integer.parseInt(st.nextToken()))) {
                sb.append(1).append(" ");
            } else sb.append(0).append(" ");
        }

        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();

    }
}