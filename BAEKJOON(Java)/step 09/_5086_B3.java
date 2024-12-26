import java.io.*;

public class _5086_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        while (true) {
            String tmp[] = br.readLine().split(" ");
            int A = Integer.parseInt(tmp[0]);
            int B = Integer.parseInt(tmp[1]);
            if (A == 0 && B == 0) break;
            if (A > B && A%B == 0) sb.append("multiple\n");
            else if (A < B && B%A == 0) sb.append("factor\n");
            else sb.append("neither\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}