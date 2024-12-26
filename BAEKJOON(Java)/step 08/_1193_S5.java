import java.io.*;

public class _1193_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int X = Integer.parseInt(br.readLine());
        int i;
        for (i = 1; i < X; i++) {
            X -= i;
        }

        if (i%2 == 0) sb.append(X).append("/").append(i-X+1).append("\n");
        else sb.append(i-X+1).append("/").append(X).append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
}