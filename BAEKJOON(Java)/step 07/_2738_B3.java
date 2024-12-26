import java.io.*;

public class _2738_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String tmp[];
        tmp = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);
        int A[][] = new int[N][M];
        int B[][] = new int[N][M];

        for (int i = 0; i < N; i++) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                A[i][j] = Integer.parseInt(tmp[j]);
            }
        }

        for (int i = 0; i < N; i++) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                B[i][j] = Integer.parseInt(tmp[j]);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                sb.append(A[i][j]+B[i][j]);
                if (j == M-1) sb.append("\n");
                else sb.append(" ");
            }
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
