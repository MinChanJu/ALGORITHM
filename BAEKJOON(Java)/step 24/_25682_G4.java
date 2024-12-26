import java.io.*;

public class _25682_G4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);
        int K = Integer.parseInt(tmp[2]);

        char board[][] = new char[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = (char) br.read();
            }
            br.read();
        }

        int prefix_sum[][] = new int[N+1][M+1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                prefix_sum[i+1][j+1] = prefix_sum[i][j+1]+prefix_sum[i+1][j]-prefix_sum[i][j];
                if ((i+j)%2 == 0 && board[i][j] == 'B') prefix_sum[i+1][j+1]++;
                if ((i+j)%2 == 1 && board[i][j] == 'W') prefix_sum[i+1][j+1]++;
            }
        }

        int min = K*K;
        for (int i = 0; i <= N-K; i++) {
            for (int j = 0; j <= M-K; j++) {
                int cnt = prefix_sum[i+K][j+K]-prefix_sum[i][j+K]-prefix_sum[i+K][j]+prefix_sum[i][j];
                cnt = Math.min(K*K-cnt, cnt);
                min = Math.min(min, cnt);
            }
        }

        System.out.println(min);
    }
}