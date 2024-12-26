import java.io.*;

public class _11718_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        String tmp;
        while ((tmp = br.readLine()) != null) {
            sb.append(tmp).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }
}
