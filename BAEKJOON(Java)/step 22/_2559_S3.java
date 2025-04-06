import java.io.*;
import java.util.StringTokenizer;

public class _2559_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int A[] = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        
        int dp[] = new int[N-K+1];
        for (int i = 0; i < K; i++) {
            dp[0] += A[i];
        }

        for (int i = 1; i <= N-K; i++) {
            dp[i] = dp[i-1] + A[i+K-1] - A[i-1];
        }

        int max = -100*K;
        for (int i = 0; i <= N-K; i++) {
            if (max < dp[i]) max = dp[i];
        }

        System.out.println(max);
    }
}