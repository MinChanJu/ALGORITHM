import java.io.*;
import java.util.*;

public class _10816_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int A[] = new int[N];
        for (int i = 0; i < N; i++) A[i] = Integer.parseInt(st.nextToken());

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int X[] = new int[M];
        for (int i = 0; i < M; i++) X[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(A);
        int s, e;
        for (int x : X) {
            int max = 0, min = 0;

            s = 0; e = N-1;
            while (s <= e) {
                int mid = (s+e)/2;
                if (A[mid] >= x) e = mid-1;
                else s = mid+1;
            }
            min = s;

            s = 0; e = N-1;
            while (s <= e) {
                int mid = (s+e)/2;
                if (A[mid] <= x) s = mid+1;
                else e = mid-1;
            }
            max = e;

            sb.append(max-min+1).append(" ");
        }
        
        sb.append("\n");

        bw.write(sb.toString());
        bw.flush();
    }
}
