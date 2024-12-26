import java.io.*;

public class _13909_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int cnt = 1;

        while (cnt*cnt <= N) {
            cnt++;
        }

        System.out.println(cnt-1);
    }
}