import java.io.*;

public class _1436_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int cnt = 0;
        int i = 1;
        while (true) {
            if (String.valueOf(i).contains("666")) cnt++;
            if (cnt == N) break;
            i++;
        }
        System.out.println(i);
    }
}