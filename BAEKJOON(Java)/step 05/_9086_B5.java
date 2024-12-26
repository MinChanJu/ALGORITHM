import java.io.*;

public class _9086_B5 {
    public static void main(String[] args0) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String tmp = br.readLine();
            System.out.println("" + tmp.charAt(0) + tmp.charAt(tmp.length()-1));
        }
    }
}
