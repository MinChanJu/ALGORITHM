import java.io.*;

public class _2839_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int result = -1;
        for (int i = N/5; i >= 0; i--) {
            if ((N-(i*5))%3 == 0) {
                result = i+((N-(i*5))/3);
                break;
            }
        }
        System.out.println(result);
    }
}