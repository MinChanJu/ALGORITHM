import java.io.*;

public class _2581_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());
        int min = 0;
        int sum = 0;
        for (int i = M; i < N+1; i++) {
            if (is_prime(i)) {
                sum += i;
                if (min == 0) min = i;
            }
        }

        if (min == 0) System.out.println(-1);
        else {
            System.out.println(sum);
            System.out.println(min);
        }
    }

    static boolean is_prime(int n) {
        if (n == 1) return false;
        for (int i = 2; i < n; i++) {
            if (n%i == 0) return false;
        }
        return true;
    }
}