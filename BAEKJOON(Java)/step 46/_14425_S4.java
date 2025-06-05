import java.io.*;
import java.util.*;

public class _14425_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);

        String str[] = new String[N];
        for (int i = 0; i < N; i++) {
            str[i] = br.readLine();
        }

        String check[] = new String[M];
        for (int i = 0; i < M; i++) {
            check[i] = br.readLine();
        }

        Map<String, Integer> map = new HashMap<>();
        for (String string : str) {
            map.put(string,1);
        }

        int cnt=0;
        for (String string : check) {
            if (map.containsKey(string)) cnt++;
        }

        System.out.println(cnt);
    }
}