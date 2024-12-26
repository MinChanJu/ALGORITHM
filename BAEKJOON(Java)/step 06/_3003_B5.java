import java.io.*;

public class _3003_B5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        String tmp[] = br.readLine().split(" ");
        int num[] = new int[6];
        num[0] = 1; num[1] = 1; num[2] = 2; num[3] = 2; num[4] = 2; num[5] = 8;
        for (int i = 0; i < tmp.length; i++) {
            sb.append(num[i]-Integer.parseInt(tmp[i]));
            if (i != 5) sb.append(" ");
        }
        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
}
