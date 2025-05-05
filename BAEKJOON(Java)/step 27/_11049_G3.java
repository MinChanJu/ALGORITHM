import java.io.*;
import java.util.*;

public class _11049_G3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    List<Matrix> matrixes = new ArrayList<>();
    for (int i = 0; i < N; i++) {
      String[] input = br.readLine().split(" ");
      matrixes.add(new Matrix(Integer.parseInt(input[0]), Integer.parseInt(input[1])));
    }

    int[][] dp = new int[N][N];
    for (int diagonal = 1; diagonal < N; diagonal++) {
      for (int i = 0; i < N - diagonal; i++) {
        int j = i + diagonal;
        dp[i][j] = dp[i][i] + dp[i + 1][j] + matrixes.get(i).r * matrixes.get(i).c * matrixes.get(j).c;
        for (int k = i + 1; k < j; k++) {
          int matrixMul = matrixes.get(i).r * matrixes.get(k).c * matrixes.get(j).c;
          dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrixMul);
        }
      }
    }

    sb.append(dp[0][N-1]).append("\n");
    bw.write(sb.toString());
    bw.flush();
  }
}

class Matrix {
  public int r, c;

  public Matrix(int r, int c) {
    this.r = r;
    this.c = c;
  }
}