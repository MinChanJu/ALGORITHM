import java.io.*;
import java.util.StringTokenizer;

public class _11053_S2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        int dp[] = new int[N];
        dp[0] = 1;
        for (int i = 1; i < N; i++) {
            int k = -1;
            for (int j = i-1; j >= 0; j--) {
                if (A[j] < A[i] && (k == -1 || dp[k] < dp[j])) k = j;
            }

            if (k == -1) dp[i] = 1;
            else dp[i] = dp[k] + 1;
        }

        int max = 0;
        for (int i = 0; i < N; i++) {
            if (max < dp[i]) max = dp[i];
        }

        System.out.println(max);
    }
}