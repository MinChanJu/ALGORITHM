import java.io.*;

public class _2903_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int i = (int) Math.pow(2, N);
        System.out.println((i+1)*(i+1));
    }
}
