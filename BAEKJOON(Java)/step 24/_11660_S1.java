import java.io.*;
import java.util.*;

public class _11660_S1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int num[][] = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) num[i][j] = Integer.parseInt(st.nextToken());
        }

        int prefix_sum[][] = new int[N+1][N+1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                prefix_sum[i+1][j+1] = prefix_sum[i+1][j]+prefix_sum[i][j+1]-prefix_sum[i][j] + num[i][j];
            }
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            int sum = prefix_sum[x2][y2]-prefix_sum[x2][y1-1]-prefix_sum[x1-1][y2]+prefix_sum[x1-1][y1-1];
            sb.append(sum).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}