import java.io.*;
import java.util.*;

public class _14888_S1 {
    static int max = -1 * (int) Math.pow(10, 9);
    static int min = (int) Math.pow(10, 9);
    static int N;
    static int num[];
    static int op[] = new int[4];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        num = new int[N];
        for (int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            op[i] = Integer.parseInt(st.nextToken());
        }

        solve(num[0], 0, op);

        System.out.println(max);
        System.out.println(min);
    }

    static void solve(int current, int pos, int A[]) {
        if (pos == N-1) {
            if (current > max) max = current;
            if (current < min) min = current;
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (A[i] > 0) {
                int next = current;
                int tmp[] = new int[4];

                for (int j = 0; j < 4; j++) tmp[j] = A[j];
                tmp[i]--;

                if (i == 0) next += num[pos+1];
                if (i == 1) next -= num[pos+1];
                if (i == 2) next *= num[pos+1];
                if (i == 3) next /= num[pos+1];

                solve(next, pos+1, tmp);
            }
        }
    }
}