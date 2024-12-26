import java.io.*;

public class _2231_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        System.out.println(solve(N));
    }

    static int solve(int N) {
        for (int i = 1; i < N; i++) {
            if (i+partSum(i) == N) return i;
        }
        return 0;
    }

    static int partSum(int n) {
        int result = 0;
        while (n != 0) {
            result += n%10;
            n /=10;
        }
        return result;
    }
}