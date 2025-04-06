import java.io.*;
import java.util.*;

public class _1912_S2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int num[] = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }

        int sum = 0;
        int max = -1000;
        for (int i : num) {
            sum += i;
            if (max < sum) max = sum;
            if (sum < 0) sum = 0;
        }

        System.out.println(max);
    }
}