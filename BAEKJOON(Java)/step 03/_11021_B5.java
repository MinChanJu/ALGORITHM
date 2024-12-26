import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class _11021_B5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String temp = br.readLine();
            int A = Integer.parseInt(temp.split(" ")[0]);
            int B = Integer.parseInt(temp.split(" ")[1]);
            sb.append("Case #").append(i+1).append(": ").append(A+B).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }
}
