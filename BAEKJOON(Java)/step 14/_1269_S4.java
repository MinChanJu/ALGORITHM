import java.io.*;
import java.util.*;

public class _1269_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input[] = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        Map<Integer,Integer> map = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            Integer A = Integer.parseInt(st.nextToken());
            map.put(A,1);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            Integer A = Integer.parseInt(st.nextToken());
            map.put(A,map.getOrDefault(A, 0)+1);
        }

        int cnt = 0;
        for (Integer key : map.keySet()) {
            if (map.get(key) == 1) cnt++;
        }

        System.out.println(cnt);
    }
}