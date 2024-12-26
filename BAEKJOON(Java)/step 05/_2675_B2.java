import java.io.*;

public class _2675_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String tmp[] = br.readLine().split(" ");
            int R = Integer.parseInt(tmp[0]);
            String S = tmp[1];
            for (int j = 0; j < S.length(); j++) {
                for (int j2 = 0; j2 < R; j2++) {
                    sb.append(S.charAt(j));
                }
            }
            sb.append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }
}
