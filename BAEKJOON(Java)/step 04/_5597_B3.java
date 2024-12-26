import java.io.*;

public class _5597_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int student[] = new int[31];
        for (int i = 0; i < 31; i++) {
            student[i] = i;
        }

        for (int i = 0; i < 28; i++) {
            int n = Integer.parseInt(br.readLine());
            student[n] = 0;
        }

        for (int i = 1; i < 31; i++) {
            if (student[i] != 0) sb.append(student[i]).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
