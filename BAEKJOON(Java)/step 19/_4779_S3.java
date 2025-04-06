import java.io.*;

public class _4779_S3 {
    static int num[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        
        String line;
        while ((line = br.readLine()) != null) {
            init(Integer.parseInt(line));
            canto(num, 0, num.length-1);
            for (int c : num) {
                if (c == 1) sb.append("-");
                else sb.append(" ");
            }
            sb.append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }

    static void canto(int num[], int l, int r) {
        int p = (r-l+1)/3;
        if (p == 0) return;
        canto(num, l, l+p-1);
        for (int i = l+p; i <= r-p; i++) {
            num[i] = 0;
        }
        canto(num,r-p+1,r);
    }

    static void init(int n) {
        int n3 = (int) Math.pow(3, n);
        num = new int[n3];
        for (int i = 0; i < n3; i++) num[i] = 1;
    }
}