import java.io.*;

public class _1934_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int p = 0; p < T; p++) {
            String tmp[] = br.readLine().split(" ");
            int A = Integer.parseInt(tmp[0]);
            int B = Integer.parseInt(tmp[1]);
            if (A > B) {
                for (int i = 1; i <= B; i++) {
                    if ((A*i)%B == 0) { sb.append(A*i).append("\n"); break; }
                }
            } else if (A < B) {
                for (int i = 1; i <= A; i++) {
                    if ((B*i)%A == 0) { sb.append(B*i).append("\n"); break; }
                }
            } else sb.append(A).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
