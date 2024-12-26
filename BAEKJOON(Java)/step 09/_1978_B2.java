import java.io.*;

public class _1978_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String tmp[] = br.readLine().split(" ");
        int cnt = 0;
        for (int k = 0; k < N; k++) {
            int i = Integer.parseInt(tmp[k]);
            if (i == 1) cnt--;
            for (int j = 2; j < i; j++) {
                if (i%j == 0) {cnt--; break;}
            }
            cnt++;
        }

        System.out.println(cnt);
    }
}