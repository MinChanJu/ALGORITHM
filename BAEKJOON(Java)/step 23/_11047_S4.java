import java.io.*;

public class _11047_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int K = Integer.parseInt(tmp[1]);

        int coin[] = new int[N];
        for (int i = 0; i < N; i++) coin[i] = Integer.parseInt(br.readLine());

        int idx = N-1, cnt = 0;
        while (K > 0) {
            if (K < coin[idx]) idx--;
            cnt += K/coin[idx];
            K %= coin[idx];
            idx--;
        }

        System.out.println(cnt);
    }
}