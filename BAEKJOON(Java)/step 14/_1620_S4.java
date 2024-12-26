import java.io.*;
import java.util.*;

public class _1620_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        Map<String, Integer> num = new HashMap<>();
        Map<Integer, String> name = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            String s = br.readLine();
            num.put(s, i);
            name.put(i, s);
        }

        for (int i = 0; i < M; i++) {
            String s = br.readLine();
            if (Character.isDigit(s.charAt(0))) {
                sb.append(name.get(Integer.parseInt(s))).append("\n");
            } else {
                sb.append(num.get(s)).append("\n");
            }
        }

        bw.write(sb.toString());
        bw.flush();
    }
}