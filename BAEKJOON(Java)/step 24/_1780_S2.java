import java.io.*;
import java.util.StringTokenizer;

public class _1780_S2 {
    static int N, a = 0, b = 0, c = 0;
    static int board[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        divide(0, 0, N-1, N-1);
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }

    static void divide(int x1, int y1, int x2, int y2) {
        int cur = board[x1][y1];
        boolean flag = true;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (cur != board[i][j]) flag = false;
            }
        }

        if (flag) {
            if (cur == -1) a++;
            if (cur == 0) b++;
            if (cur == 1) c++;
        } else {
            int dx = (x2-x1+1)/3, dy = (y2-y1+1)/3;
            for (int i = x1; i <= x2; i += dx) {
                for (int j = y1; j <= y2; j += dy) {
                    divide(i, j, i+dx-1, j+dy-1);
                }
            }
        }
    }
}