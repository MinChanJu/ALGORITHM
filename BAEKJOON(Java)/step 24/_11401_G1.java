import java.io.*;

public class _11401_G1 {
    static int p = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String tmp[] = br.readLine().split(" ");
        long N = Integer.parseInt(tmp[0]);
        long K = Integer.parseInt(tmp[1]);

        long top = fact(N);
        long bottom = (fact(N-K)*fact(K))%p;
        bottom = pow(bottom, p-2);

        System.out.println((top*bottom)%p);
    }

    static long fact(long n) {
        long mul = 1;
        for (long i = 2; i <= n; i++) {
            mul = (mul*i)%p;
        }
        return mul;
    }

    static long pow(long n, long size) {
        if (size == 1) return n%p;

        long k = pow(n, size/2);
        k = (k*k)%p;

        if (size%2 == 0) return k;
        return (k*n)%p;
    }
}