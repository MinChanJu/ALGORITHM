import java.io.*;

public class _24267_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        System.out.println(((long) N*(N-1)*(N-2)/6) + "\n3");
    }
}