import java.io.*;

public class _27433_B5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(fact(Integer.parseInt(br.readLine())));
    }

    static long fact(int n) {
        if (n < 1) return 1;
        return n*fact(n-1);
    }
}
