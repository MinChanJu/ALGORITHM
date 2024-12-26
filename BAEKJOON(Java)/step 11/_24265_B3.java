import java.io.*;

public class _24265_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long result = 0;
        for (int i = 0; i < N; i++) {
            result += i;
        }
        System.out.println(result + "\n2");
    }
}