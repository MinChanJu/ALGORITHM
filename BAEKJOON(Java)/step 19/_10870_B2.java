import java.io.*;

public class _10870_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(fibo(Integer.parseInt(br.readLine())));
    }

    static int fibo(int n) {
    if (n <= 1) return n;
    return fibo(n-1) + fibo(n-2);
    }
}