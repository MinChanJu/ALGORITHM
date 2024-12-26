import java.io.*;
import java.util.*;

public class _7785_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        Map<String,Integer> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String tmp[] = br.readLine().split(" ");
            if (tmp[1].equals("enter")) map.put(tmp[0], 1);
            else map.put(tmp[0],0);
        }

        int cnt = 0;
        for (String key : map.keySet()) {
            if (map.get(key) == 1) cnt++;
        }

        String ent[] = new String[cnt];
        int i = 0;

        for (String key : map.keySet()) {
            if (map.get(key) == 1) ent[i++] = key;
        }

        Arrays.sort(ent);

        for (i = i-1; i >= 0; i--) {
            sb.append(ent[i]).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}