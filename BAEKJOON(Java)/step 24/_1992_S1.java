import java.io.*;

public class _1992_S1 {
    static int N;
    static int board[][];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        board = new int[N+1][N+1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i+1][j+1] = board[i+1][j] + board[i][j+1] - board[i][j] + br.read()-48;
            }
            br.read();
        }

        divide(0, 0, N-1, N-1);

        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();
    }

    static void divide(int x1, int y1, int x2, int y2) {
        int sum = board[x2+1][y2+1]-board[x1][y2+1]-board[x2+1][y1]+board[x1][y1];

        if (sum == 0) sb.append(0);
        else if (sum == (x2-x1+1)*(y2-y1+1)) sb.append(1);
        else {
            int midX = (x1+x2)/2, midY = (y1+y2)/2;
            sb.append("(");
            divide(x1, y1, midX, midY);
            divide(x1, midY+1, midX, y2);
            divide(midX+1, y1, x2, midY);
            divide(midX+1, midY+1, x2, y2);
            sb.append(")");
        }
    }
}