import java.io.*;

public class _1316_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int j;
        int T = Integer.parseInt(br.readLine());
        int total = 0;
        for (int i = 0; i < T; i++) {
            String tmp = br.readLine();
            int last = tmp.charAt(0);
            int cnt[] = new int[26];
            cnt[last-97] = 1;

            for (j = 1; j < tmp.length(); j++) {
                if (last == tmp.charAt(j)) continue;
                if (cnt[tmp.charAt(j)-97] == 1) break;
                last = tmp.charAt(j);
                cnt[tmp.charAt(j)-97] = 1; 
            }

            if (j == tmp.length()) total++;
        }

        System.out.println(total);
    }
}
