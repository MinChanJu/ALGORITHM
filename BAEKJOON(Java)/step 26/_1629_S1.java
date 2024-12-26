import java.io.*;
import java.util.StringTokenizer;

public class _1629_S1 {
    static long A, B, C;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        System.out.println(divide(B));
    }

    static long divide(long size) {
        if (size == 1) return A%C;
        long k = divide(size/2);
        if (size%2 == 0) return (k*k)%C;
        return (((k*k)%C)*(A%C))%C;
    }
}