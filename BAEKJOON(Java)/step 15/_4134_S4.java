import java.io.*;

public class _4134_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            long n = Long.parseLong(br.readLine());
            
            while (true) {
                int k = 0;
                if (n <= 1) {n = 2; break;}
                for (long i = 2; i <= Math.sqrt(n); i++) {
                    if (n%i == 0) {
                        k = 1;
                        break;
                    }
                }
                if (k == 0) break;
                n++;
            }

            sb.append(n).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}