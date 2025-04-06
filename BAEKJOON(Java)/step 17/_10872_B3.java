import java.io.*;

public class _10872_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int sum = 1;
        for (int i = 2; i <= N; i++) {
            sum *= i;
        }

        System.out.println(sum);
    }
}