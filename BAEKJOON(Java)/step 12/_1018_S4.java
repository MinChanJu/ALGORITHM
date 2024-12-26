import java.io.*;

public class _1018_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);
        char board[][] = new char[N][M];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = line.charAt(j);
            }
        }

        int min = 64;
        for (int i = 0; i < N-7; i++) {
            for (int j = 0; j < M-7; j++) {
                int cnt = 0;
                char check = 'B';
                for (int i2 = i; i2 < i+8; i2++) {
                    for (int j2 = j; j2 < j+8; j2++) {
                        if (j2 == j) {
                            if (check == 'B') check = 'W';
                            else if (check == 'W') check = 'B';
                        }
                        if (board[i2][j2] != check) cnt++;
                        if (check == 'B') check = 'W';
                        else if (check == 'W') check = 'B';
                    }
                }
                min = Math.min(min, Math.min(64-cnt, cnt));
            }
        }

        System.out.println(min);
    }
}