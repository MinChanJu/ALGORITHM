import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class _2739_B5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for (int i = 1; i < 10; i++) {
            System.out.println(N + " * " + i + " = " + (N*i));
        }
    }
}
