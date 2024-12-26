import java.io.*;
import java.util.StringTokenizer;

public class _13305_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        long distance[] = new long[N-1];
        for (int i = 0; i < N-1; i++) distance[i] = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        long oil[] = new long[N];
        oil[0] = Integer.parseInt(st.nextToken());
        for (int i = 1; i < N; i++) {
            long x = Integer.parseInt(st.nextToken());
            if (oil[i-1] < x) oil[i] = oil[i-1];
            else oil[i] = x;
        }

        long sum = 0;
        for (int i = 0; i < N-1; i++) sum += oil[i]*distance[i];

        System.out.println(sum);
    }
}