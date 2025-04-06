import java.io.*;
import java.util.*;

public class _10986_G3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int prefix_sum[] = new int[N+1];
        for (int i = 1; i <= N; i++) prefix_sum[i] = (prefix_sum[i-1]+Integer.parseInt(st.nextToken())%M)%M;

        long num[] = new long[M];
        for (int i = 1; i <= N; i++) num[prefix_sum[i]]++;

        long cnt = 0;
        for (int i = 0; i < M; i++) {
            if (num[i] == 0) continue;
            if (i != 0 && num[i] == 1) continue;

            if (i == 0) cnt += (num[i]+1)*num[i] / 2;
            else cnt += (num[i]-1)*num[i] / 2;
        }

        sb.append(cnt).append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
}