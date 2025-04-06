import java.io.*;

public class _16139_S1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String S = br.readLine();
        int alpha[][] = new int[26][S.length()+1];
        for (int i = 0; i < S.length(); i++) {
            for (int j = 0; j < 26; j++) {
                alpha[j][i+1] = alpha[j][i];
                if (S.charAt(i) == j+97) alpha[j][i+1]++;
            }
        }

        int q = Integer.parseInt(br.readLine());
        while (q-- != 0) {
            String tmp[] = br.readLine().split(" ");
            int a = tmp[0].charAt(0);
            int l = Integer.parseInt(tmp[1]);
            int r = Integer.parseInt(tmp[2]);

            sb.append(alpha[a-97][r+1]-alpha[a-97][l]).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}