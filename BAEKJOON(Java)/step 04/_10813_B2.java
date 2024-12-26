import java.io.*;

public class _10813_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);
        int map[] = new int[N+1];

        for (int i = 0; i < map.length; i++) {
            map[i] = i;
        }

        for (int p = 0; p < M; p++) {
            tmp = br.readLine().split(" ");
            int i = Integer.parseInt(tmp[0]);
            int j = Integer.parseInt(tmp[1]);
            int tmp2 = map[i];
            map[i] = map[j];
            map[j] = tmp2;
        }

        for (int i = 1; i < N+1; i++) {
            sb.append(map[i]);
            if (i != N) sb.append(" ");
        }

        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
    
}