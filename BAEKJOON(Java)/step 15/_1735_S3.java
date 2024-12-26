import java.io.*;

public class _1735_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp[] = br.readLine().split(" ");
        int a1 = Integer.parseInt(tmp[0]);
        int b1 = Integer.parseInt(tmp[1]);
        tmp = br.readLine().split(" ");
        int a2 = Integer.parseInt(tmp[0]);
        int b2 = Integer.parseInt(tmp[1]);

        int lcm = b1*b2/gcd(b1,b2);
        int A = (a1*(lcm/b1))+(a2*(lcm/b2));
        int g = gcd(lcm,A);
        System.out.println((A/g) + " " + (lcm/g));
    }

    static int gcd(int a, int b) {
        if (a%b == 0) return b;
        return gcd(b,a%b);
    }
}