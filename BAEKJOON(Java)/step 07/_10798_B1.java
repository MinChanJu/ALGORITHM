import java.io.*;

public class _10798_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int A[][] = new int[5][15];
        String tmp;
        for (int i = 0; i < A.length; i++) {
            tmp = br.readLine();
            for (int j = 0; j < tmp.length(); j++) {
                A[i][j] = tmp.charAt(j);
            }
            for (int j = tmp.length(); j < 15; j++) {
                A[i][j] = -1;
            }
        }
        for (int j = 0; j < 15; j++) {
            for (int i = 0; i < 5; i++) {
                if (A[i][j] != -1) sb.append((char) A[i][j]);
            }
        }
        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
}
