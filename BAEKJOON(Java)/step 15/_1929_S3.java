import java.io.*;

public class _1929_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);

        int num[] = new int[M+1];
        for (int i = 2; i <= M; i++) {
            num[i] = 1;
        }

        for (int i = 2; i <= M; i++) {
            if (num[i] == 1) {
                for (int j = i+i; j <= M; j += i) {
                    num[j] = 0;
                }
            }
        }

        for (int i = N; i <= M; i++) {
            if (num[i] == 1) sb.append(i).append("\n");
        }
        
        System.out.println(sb);
    }
}