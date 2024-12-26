import java.io.*;

public class _1427_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String tmp = br.readLine();
        int num[] = new int[10];

        for (int i = 0; i < tmp.length(); i++) {
            num[tmp.charAt(i)-48]++;
        }

        for (int i = 9; i >= 0; i--) {
            while (num[i] > 0) {
                sb.append(i);
                num[i]--;
            }
        }

        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
}