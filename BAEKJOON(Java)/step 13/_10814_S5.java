import java.io.*;
import java.util.*;

public class _10814_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        String baek[][] = new String[N][2];

        for (int i = 0; i < N; i++) {
            String tmp[] = br.readLine().split(" ");
            baek[i][0] = tmp[0];
            baek[i][1] = tmp[1];
        }

        Arrays.sort(baek, (a,b) -> Integer.parseInt(a[0]) - Integer.parseInt(b[0]));

        for (int i = 0; i < N; i++) {
            sb.append(baek[i][0]+" "+baek[i][1]+"\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}