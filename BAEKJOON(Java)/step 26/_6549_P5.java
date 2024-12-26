import java.io.*;
import java.util.StringTokenizer;

public class _6549_P5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken());
            if (N == 0) break;

            int H[] = new int[N+1];
            for (int i = 0; i < N; i++) H[i] = Integer.parseInt(st.nextToken());

            int lp[] = new int[N+1];
            int top = 0;

            long MAX = H[1];
            for (int i = 0; i < N+1; i++) {
                while (top > 0 && H[lp[top-1]] > H[i]) {
                    int t = lp[--top];
                    int s = i;
                    if (top > 0) s -= lp[top-1] + 1;
                    MAX = Math.max(MAX, (long) H[t] * s);
                }
                lp[top++] = i;
            }

            sb.append(MAX).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}