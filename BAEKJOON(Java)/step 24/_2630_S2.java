import java.io.*;
import java.util.StringTokenizer;

public class _2630_S2 {
    static int N, blue = 0, white = 0;
    static int board[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        board = new int[N+1][N+1];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i+1][j+1] = board[i+1][j] + board[i][j+1] - board[i][j] + Integer.parseInt(st.nextToken());
            }
        }

        divide(0, 0, N-1, N-1);

        System.out.println(white);
        System.out.println(blue);
    }

    static void divide(int x1, int y1, int x2, int y2) {
        int sum = board[x2+1][y2+1]-board[x1][y2+1]-board[x2+1][y1]+board[x1][y1];

        if (sum == 0) white++;
        else if (sum == (x2-x1+1)*(y2-y1+1)) blue++;
        else {
            int midX = (x1+x2)/2, midY = (y1+y2)/2;
            divide(x1, y1, midX, midY);
            divide(midX+1, y1, x2, midY);
            divide(x1, midY+1, midX, y2);
            divide(midX+1, midY+1, x2, y2);
        }
    }
}