import java.io.*;
import java.util.*;

public class _2485_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int num[] = new int[N];
        for (int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(num);
        for (int i = 1; i < N; i++) {
            num[i] -= num[0];
        }

        int last = gcd(num[1],num[2]);
        for (int i = 3; i < N; i++) {
            last = gcd(last,num[i]);
        }

        int cur = num[0]+last;
        int cnt = 0;
        for (int i = 1; i < N; i++) {
            num[i] += num[0];
            while (num[i] > cur) {
                cnt++;
                cur += last;
            }
            if (num[i] == cur) cur += last;
        }

        System.out.println(cnt);
    }

    static int gcd(int a, int b) {
        if (a%b == 0) return b;
        return gcd(b,a%b);
    }
}