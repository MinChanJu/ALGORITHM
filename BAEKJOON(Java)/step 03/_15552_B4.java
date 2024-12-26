import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class _15552_B4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String temp = br.readLine();
            int a = Integer.parseInt(temp.split(" ")[0]);
            int b = Integer.parseInt(temp.split(" ")[1]);
            sb.append(a+b).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }
}
