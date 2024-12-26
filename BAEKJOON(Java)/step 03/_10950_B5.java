import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class _10950_B5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        String tmp;
        int A,B;
        for (int i = 0; i < T; i++) {
            tmp = br.readLine();
            A = Integer.parseInt(tmp.split(" ")[0]);
            B = Integer.parseInt(tmp.split(" ")[1]);
            System.out.println(A+B);
        }
    }
}
