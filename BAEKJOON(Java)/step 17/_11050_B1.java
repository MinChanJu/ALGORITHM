import java.io.*;

public class _11050_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int K = Integer.parseInt(tmp[1]);
        
        System.out.println(fact(N)/fact(N-K)/fact(K));
    }

    static int fact(int n) {
        int result = 1;
        for (int i = 2 ; i <= n; i++) result *= i;
        return result;
    }
}