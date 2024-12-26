import java.io.*;

public class _1546_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String score[] = br.readLine().split(" ");
        double score2[] = new double[score.length];
        double max = 0;
        for (int i = 0; i < N; i++) {
            score2[i] = Double.parseDouble(score[i]);
            if (max < score2[i]) max = score2[i];
        }

        for (int i = 0; i < N; i++) {
            score2[i] = score2[i]/max*100;
        }

        double total = 0;

        for (double d : score2) {
            total += d;
        }

        System.out.println(total/N);
    }
}
