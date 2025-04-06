import java.io.*;

public class _11729_G5 {
    static StringBuilder sb = new StringBuilder();
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        Hanoi(N, 1, 2, 3);
        System.out.println(cnt);
        System.out.print(sb);
    }

    static void Hanoi(int n, int a, int b, int c) {
        if (n >= 1) {
            Hanoi(n-1, a, c, b);
            sb.append(a).append(" ").append(c).append("\n");
            cnt++;
            Hanoi(n-1, b, a, c);
        }
    }
}