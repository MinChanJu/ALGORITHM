import java.io.*;
import java.util.*;

public class _1931_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int meeting[][] = new int[N][2];
        int max = 0;

        for (int i = 0; i < N; i++) {
            String tmp[] = br.readLine().split(" ");
            meeting[i][0] = Integer.parseInt(tmp[0]);
            meeting[i][1] = Integer.parseInt(tmp[1]);
            if (max < meeting[i][1]) max = meeting[i][1];
        }

        Arrays.sort(meeting, (a, b) -> {
            if (a[1] == b[1]) return a[0] - b[0];
            return a[1] - b[1];
        });

        int cnt = 0, last = 0;
        for (int i = 0; i < N; i++) {
            if (last <= meeting[i][0]) {
                cnt++;
                last = meeting[i][1];
            }
        }

        System.out.println(cnt);
    }
}
