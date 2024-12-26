import java.io.*;
import java.util.StringTokenizer;

public class _13241_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long A = Long.parseLong(st.nextToken());
        long B = Long.parseLong(st.nextToken());
        long g = gcd(A,B);
        long lcm = (A*B)/g;
        System.out.println(lcm);
    }

    static long gcd(long a, long b) {
        if (a%b == 0) return b;
        return gcd(b,a%b);
    }
}