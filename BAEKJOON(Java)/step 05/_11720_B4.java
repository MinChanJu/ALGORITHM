import java.io.*;

public class _11720_B4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String tmp[] = br.readLine().split("");
        int total = 0;
        for (int i = 0; i < N; i++) {
            total += Integer.parseInt(tmp[i]);
        }
        System.out.println(total);
    }
}
