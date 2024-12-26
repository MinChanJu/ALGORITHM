import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class _10951_B5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        String temp;
        while ((temp = br.readLine()) != null) {
            int A = Integer.parseInt(temp.split(" ")[0]);
            int B = Integer.parseInt(temp.split(" ")[1]);
            sb.append(A+B).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }
}