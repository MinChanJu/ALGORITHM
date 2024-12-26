import java.io.*;

public class _11005_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int B = Integer.parseInt(tmp[1]);
        while (N != 0) {
            if (N%B >= 10) sb.append((char) (N%B+55));
            else sb.append(N%B);
            N /= B;
        }
        sb.reverse();
        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
}