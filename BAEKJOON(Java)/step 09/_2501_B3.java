import java.io.*;

public class _2501_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int K = Integer.parseInt(tmp[1]);

        int cnt = 0;

        for (int i = 1; i < N+1; i++) {
            if (N%i == 0) cnt++;
            if(cnt == K) {
                System.out.println(i);
                break;
            }
        }

        if (cnt != K) System.out.println(0);
    }
}