import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class _10871_B5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        String temp = br.readLine();
        int N = Integer.parseInt(temp.split(" ")[0]);
        int X = Integer.parseInt(temp.split(" ")[1]);
        String[] A = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            int cur = Integer.parseInt(A[i]);
            if (cur < X) sb.append(cur).append(" ");
        }
        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();
    }
}
