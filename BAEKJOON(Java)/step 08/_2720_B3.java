import java.io.*;

public class _2720_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int C;
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            C = Integer.parseInt(br.readLine());
            sb.append(C/25).append(" ");
            C %= 25;
            sb.append(C/10).append(" ");
            C %= 10;
            sb.append(C/5).append(" ");
            C %= 5;
            sb.append(C).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
