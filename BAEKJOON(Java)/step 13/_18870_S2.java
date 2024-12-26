import java.io.*;
import java.util.*;

public class _18870_S2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int X[] = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = Integer.parseInt(st.nextToken());
        }

        Integer Y[] = new Integer[N];
        for (int i = 0; i < N; i++) {
            Y[i] = X[i];
        }

        Set<Integer> set = new HashSet<>(Arrays.asList(Y));
        Y = set.toArray(new Integer[0]);

        Arrays.sort(Y);

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < Y.length; i++) {
            map.put(Y[i],i);
        }

        for (int i = 0; i < N; i++) {
            sb.append(map.get(X[i])).append(" ");
        }

        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
}