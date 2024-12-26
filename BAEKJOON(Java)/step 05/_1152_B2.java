import java.io.*;

public class _1152_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S[] = br.readLine().trim().split(" +");
        if (S.length == 1 && S[0].isEmpty()) {
            System.out.println(0);
        } else {
            System.out.println(S.length);
        }
    }
}
