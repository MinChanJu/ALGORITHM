import java.io.*;
import java.util.*;

public class _1520_G3 {
  static int[] dx = { 1, 0, 0, -1 }, dy = { 0, 1, -1, 0 };
  static int[][] map, dp;
  static int M, N;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    StringTokenizer st = new StringTokenizer(br.readLine());
    M = Integer.parseInt(st.nextToken());
    N = Integer.parseInt(st.nextToken());

    map = new int[M][N];
    dp = new int[M][N];
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < N; j++) {
        map[i][j] = Integer.parseInt(st.nextToken());
        dp[i][j] = -1;
      }
    }

    sb.append(DFS(0, 0)).append("\n");

    bw.write(sb.toString());
    bw.flush();
  }

  static int DFS(int x, int y) {
    if (x == M - 1 && y == N - 1)
      return 1;

    if (dp[x][y] != -1)
      return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (0 <= nx && nx < M && 0 <= ny && ny < N) {
        if (map[x][y] > map[nx][ny])
          dp[x][y] += DFS(nx, ny);
      }
    }

    return dp[x][y];
  }
}