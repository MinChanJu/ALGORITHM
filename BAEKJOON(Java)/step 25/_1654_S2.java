import java.io.*;
import java.util.*;

public class _1654_S2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int len[] = new int[K];
        for (int i = 0; i < K; i++) len[i] = Integer.parseInt(br.readLine());
        
        long s = 1, e = len[0];
        for (int i = 1; i < K; i++) e = Math.max(e, len[i]);

        while (s <= e) {
            long mid = (s+e)/2;

            long cnt = 0;
            for (int i = 0; i < K; i++) cnt += len[i]/mid;

            if (cnt >= N) s = mid+1;
            else e = mid-1;
        }

        sb.append(e).append("\n");

        bw.write(sb.toString());
        bw.flush();
    }
}