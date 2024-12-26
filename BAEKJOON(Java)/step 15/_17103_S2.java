import java.io.*;

public class _17103_S2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int num[] = new int[1000000];
        for (int i = 2; i < num.length; i++) {
            num[i] = 1;
        }

        for (int i = 0; i < num.length; i++) {
            if (num[i] == 1) {
                for (int j = i+i; j < num.length; j += i) {
                    num[j] = 0;
                }
            }
        }

        int T = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < T; tc++) {
            int N = Integer.parseInt(br.readLine());
            int cnt = 0;
            for (int i = 2; i <= N/2; i++) {
                if (num[i] == 1 && num[N-i] == 1) cnt++;
            }
            sb.append(cnt).append("\n");
        }

        System.out.print(sb);
    }
}