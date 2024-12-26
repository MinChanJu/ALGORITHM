import java.io.*;
import java.util.*;

public class _1181_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        String str[] = new String[N];
        for (int i = 0; i < N; i++) {
            str[i] = br.readLine();
        }

        Set<String> uniqueSet = new LinkedHashSet<>(Arrays.asList(str));
        str = uniqueSet.toArray(new String[0]);

        Arrays.sort(str, Comparator.comparingInt(String::length).thenComparing(Comparator.naturalOrder()));

        for (int i = 0; i < str.length; i++) {
            sb.append(str[i]).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}