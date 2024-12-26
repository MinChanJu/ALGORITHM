import java.io.*;
import java.util.*;

public class _2751_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        Integer num[] = new Integer[N];
        for (int i = 0; i < num.length; i++) {
            num[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(num);
        for (int i = 0; i < num.length; i++) {
            sb.append(num[i]).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }
}