import java.io.*;

public class _12865_G5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int K = Integer.parseInt(input[1]);

        int A[][] = new int[N][2];
        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            int W = Integer.parseInt(input[0]);
            int V = Integer.parseInt(input[1]);
            A[i][0] = W;
            A[i][1] = V;
        }

        int dp[] = new int[K+1];
        for (int i = 0; i < N; i++) {
            int W = A[i][0];
            int V = A[i][1];
            
            for (int j = K-W; j >= 0; j--) {
                dp[j+W] = Math.max(dp[j+W], dp[j]+V);
            }
        }

        System.out.println(dp[K]);
    }
}