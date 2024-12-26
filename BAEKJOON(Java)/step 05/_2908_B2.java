import java.io.*;

public class _2908_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp[] = br.readLine().split(" ");
        StringBuilder reversed = new StringBuilder(tmp[0]);
        reversed.reverse();
        int A = Integer.parseInt(reversed.toString());
        reversed = new StringBuilder(tmp[1]);
        reversed.reverse();
        int B = Integer.parseInt(reversed.toString());
        if (A > B) System.out.println(A);
        else System.out.println(B);
    }
}