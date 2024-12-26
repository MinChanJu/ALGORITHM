import java.io.*;

public class _5073_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        String tmp[];
        while (true) {
            tmp = br.readLine().split(" ");

            int a = Integer.parseInt(tmp[0]);
            int b = Integer.parseInt(tmp[1]);
            int c = Integer.parseInt(tmp[2]);

            if (a == 0) break;

            if (a == b && b == c) sb.append("Equilateral\n");
            else if (Math.max(Math.max(a,b),c) >= a+b+c-Math.max(Math.max(a,b),c)) sb.append("Invalid\n");
            else if (a == b || b == c || a == c) sb.append("Isosceles\n");
            else sb.append("Scalene\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}