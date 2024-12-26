import java.io.*;

public class _2566_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String tmp[];
        int A[][] = new int[9][9];
        for (int i = 0; i < 9; i++) {
            tmp = br.readLine().split(" ");
            for (int j = 0; j < 9; j++) {
                A[i][j] = Integer.parseInt(tmp[j]);
            }
        }

        int maxi=0, maxj=0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (A[maxi][maxj] < A[i][j]) {
                    maxi = i; maxj = j;
                }
            }
        }

        System.out.println(A[maxi][maxj]);
        System.out.println((maxi+1) + " " + (maxj+1));
    }
}
