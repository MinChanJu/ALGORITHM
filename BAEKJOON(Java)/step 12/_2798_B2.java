import java.io.*;

public class _2798_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String num[] = br.readLine().split(" ");
        int N = Integer.parseInt(num[0]);
        int M = Integer.parseInt(num[1]);
        int max = 0;
        num = br.readLine().split(" ");
        for (int i = 0; i < N-2; i++) {
            for (int j = i+1; j < N-1; j++) {
                for (int k = j+1; k < N; k++) {
                    int sum = Integer.parseInt(num[i]) + Integer.parseInt(num[j]) + Integer.parseInt(num[k]);
                    if (sum > max && sum <= M) max = sum;
                }
            }
        }

        System.out.println(max);
    }
}