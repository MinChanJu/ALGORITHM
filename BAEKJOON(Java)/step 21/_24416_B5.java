import java.io.*;

public class _24416_B5 {
    static int recur_cnt = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        fib(N);
        System.out.println(recur_cnt + " " + (N-2));
    }

    static int fib(int n) {
        if (n == 1 || n == 2) return 1;
        recur_cnt++;
        return fib(n-1) + fib(n-2);
    }
}