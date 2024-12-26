import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class _1920_S4 {
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
        for (int x : X) {
            int mid = 0, s = 0, e = N-1;
            while (s <= e) {
                mid = (s+e)/2;
                if (A[mid] == x) break;
                else if (A[mid] > x) e = mid-1;
                else if (A[mid] < x) s = mid+1;
            }
            if (A[mid] == x) sb.append(1).append("\n");
            else sb.append(0).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}