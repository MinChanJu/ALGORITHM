import java.io.*;

public class _10809_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        String S = br.readLine();
        int num[] = new int[26];

        for (int i = 0; i < num.length; i++) {
            num[i] = -1;
        }

        for (int i=0; i < S.length(); i++) {
            if(num[(int) S.charAt(i) - 97] == -1) {
                num[(int) S.charAt(i)-97] = i;
            }
        }

        for (int i = 0; i < num.length; i++) {
            sb.append(num[i]);
            if (i != 25) sb.append(" ");
            else sb.append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
