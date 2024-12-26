import java.io.*;
import java.util.*;

public class _1764_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            map.put(tmp,1);
        }

        for (int i = 0; i < M; i++) {
            String tmp = br.readLine();
            map.put(tmp, map.getOrDefault(tmp, 0)+1);
        }

        int cnt = 0;
        for (String key : map.keySet()) {
            if (map.get(key) == 2) cnt++;
        }

        String dbj[] = new String[cnt];
        int i = 0;
        for (String key : map.keySet()) {
            if (map.get(key) == 2) dbj[i++] = key;
        }

        Arrays.sort(dbj);
        sb.append(cnt).append("\n");
        for (String string : dbj) {
            sb.append(string).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}