import java.io.*;

public class _9506_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        while (true) {
            int n = Integer.parseInt(br.readLine());
            StringBuilder divisor = new StringBuilder();
            
            if (n == -1) break;

            int total = 1;
            divisor.append(1);
            for (int i = 2; i < n; i++) {
                if (n%i == 0) {total += i; divisor.append(" + ").append(i);}
            }

            if (total == n) sb.append(n).append(" = ").append(divisor.toString()).append("\n");
            else sb.append(n).append(" is NOT perfect.\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
