import java.io.*;

public class _2447_G5 {
    static int num[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        init(N);
        star(0, 0, N-1, N-1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (num[i][j] == 1) sb.append("*");
                else sb.append(" ");
            }
            sb.append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }

    static void star(int x1, int y1, int x2, int y2) {
        int p = (x2-x1+1) / 3;
        if (p == 0) return;

        star(x1, y1, x1+p-1, y1+p-1);
        star(x1+p, y1, x1+p+p-1, y1+p-1);
        star(x1+p+p, y1, x1+p+p+p-1, y1+p-1);

        star(x1, y1+p, x1+p-1, y1+p+p-1);
        for (int i = x1+p; i < x1+p+p; i++) {
            for (int j = y1+p; j < y1+p+p; j++) {
                num[i][j] = 0;
            }
        }
        star(x1+p+p, y1+p, x1+p+p+p-1, y1+p+p-1);

        star(x1, y1+p+p, x1+p-1, y1+p+p+p-1);
        star(x1+p, y1+p+p, x1+p+p-1, y1+p+p+p-1);
        star(x1+p+p, y1+p+p, x1+p+p+p-1, y1+p+p+p-1);
        
    }

    static void init(int n) {
        num = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                num[i][j] = 1;
            }
        }
    }
}