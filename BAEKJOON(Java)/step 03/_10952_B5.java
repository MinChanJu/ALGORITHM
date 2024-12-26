import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class _10952_B5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        while (true) {
            String temp = br.readLine();
            int A = Integer.parseInt(temp.split(" ")[0]);
            int B = Integer.parseInt(temp.split(" ")[1]);
            if (A == 0 && B == 0) break;
            sb.append(A+B).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }
}
