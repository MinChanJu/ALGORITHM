import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class _25304_B4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int X = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());
        String tmp;
        int a, b, sum = 0;
        for (int i = 0; i < N; i++) {
            tmp = br.readLine();
            a = Integer.parseInt(tmp.split(" ")[0]);
            b = Integer.parseInt(tmp.split(" ")[1]);
            sum += a*b;
        }
        if (sum == X) System.out.println("Yes");
        else System.out.println("No");
    }
}
