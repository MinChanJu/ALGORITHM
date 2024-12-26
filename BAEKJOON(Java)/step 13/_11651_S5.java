import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class _11651_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        String tmp[];
        int num[][] = new int[N][2];

        for (int i = 0; i < N; i++) {
            tmp = br.readLine().split(" ");
            num[i][0] = Integer.parseInt(tmp[0]);
            num[i][1] = Integer.parseInt(tmp[1]);
        }

        Arrays.sort(num, Comparator.comparingInt((int[] a) -> a[1]).thenComparingInt(a -> a[0]));

        for (int i = 0; i < N; i++) {
            sb.append(num[i][0]).append(" ").append(num[i][1]).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}