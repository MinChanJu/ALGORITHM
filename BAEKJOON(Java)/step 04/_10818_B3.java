import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class _10818_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] A = br.readLine().split(" ");
        int max = -1000000, min = 1000000;
        for (int i = 0; i < N; i++) {
            int X = Integer.parseInt(A[i]);
            if (X > max) max = X;
            if (X < min) min = X;
        }
        System.out.println(min + " " + max);
    }
}
