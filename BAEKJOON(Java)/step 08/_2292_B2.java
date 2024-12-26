import java.io.*;

public class _2292_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int i = 1, j = 6;
        while (i < N) {
            i += j;
            j += 6;
        }
        System.out.println(j / 6);
    }
}
