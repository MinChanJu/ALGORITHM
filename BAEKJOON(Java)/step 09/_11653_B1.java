import java.io.*;

public class _11653_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        while (N != 1) {
            for (int i = 2; i < N+1; i++) {
                if (N%i == 0) {
                    sb.append(i).append("\n");
                    N /= i;
                    break;
                }
            }
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
