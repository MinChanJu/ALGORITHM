import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class _1037_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Integer num[] = new Integer[N];
        for (int i = 0; i < N; i++) num[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(num);
        System.out.println(num[0]*num[N-1]);
    }
}