import java.io.*;
import java.util.StringTokenizer;

public class _11054_G4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int A[] = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int UpDp[] = new int[N];
        UpDp[0] = 1;
        for (int i = 1; i < N; i++) {
            UpDp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (A[j] < A[i]) UpDp[i] = Math.max(UpDp[j] + 1, UpDp[i]);
            }
        }

        int DownDp[] = new int[N];
        DownDp[N-1] = 1;
        for (int i = N-2; i >= 0; i--) {
            DownDp[i] = 1;
            for (int j = i+1; j < N; j++) {
                if (A[i] > A[j]) DownDp[i] = Math.max(DownDp[j] + 1, DownDp[i]);
            }
        }

        int max = 0;
        for (int i = 0; i < N; i++) {
            if (max < UpDp[i]+DownDp[i]-1) max = UpDp[i]+DownDp[i]-1;
        }
        
        System.out.println(max);
    }
}