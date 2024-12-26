import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class _10810_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);
        int map[] = new int[N+1];
        for (int p = 0; p < M; p++) {
            tmp = br.readLine().split(" ");
            int i = Integer.parseInt(tmp[0]);
            int j = Integer.parseInt(tmp[1]);
            int k = Integer.parseInt(tmp[2]);
            for (int k2 = i; k2 < j+1; k2++) {
                map[k2] = k;
            }
        }

        for (int i = 1; i < N+1; i++) {
            sb.append(map[i]);
            if (i != N) sb.append(" ");
        }

        System.out.println(sb);
    }
}
