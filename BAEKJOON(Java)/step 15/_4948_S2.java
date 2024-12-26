import java.io.*;

public class _4948_S2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int to = 123456*2+1;
        int num[] = new int[to];
        for (int i = 2; i < to; i++) {
            num[i] = 1;
        }

        for (int i = 2; i < to; i++) {
            if (num[i] == 1) {
                for (int j = i+i; j < to; j += i) {
                    num[j] = 0;
                }
            }
        }

        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            int cnt = 0;
            for (int i = n+1; i <= 2*n; i++) { if (num[i] == 1) cnt++; }
            sb.append(cnt).append("\n");
        }

        System.out.println(sb);
    }
}