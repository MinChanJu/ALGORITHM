import java.io.*;

public class _10988_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        StringBuilder reversed = new StringBuilder(S);
        reversed.reverse();
        if (S.equals(reversed.toString())) System.out.println(1);
        else System.out.println(0);
    }
}
