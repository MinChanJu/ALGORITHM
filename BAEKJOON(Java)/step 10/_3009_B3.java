import java.io.*;
import java.util.StringTokenizer;

public class _3009_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int x1 = Integer.parseInt(st.nextToken());
        int y1 = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int x2 = Integer.parseInt(st.nextToken());
        int y2 = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int x3 = Integer.parseInt(st.nextToken());
        int y3 = Integer.parseInt(st.nextToken());

        if (x1 == x2) {
            if (y1 == y3) System.out.println(x3 + " " + y2);
            else if (y2 == y3) System.out.println(x3 + " " + y1);
        } else if (x1 == x3) {
            if (y1 == y2) System.out.println(x2 + " " + y3);
            else if (y3 == y2) System.out.println(x2 + " " + y1);
        } else if (x2 == x3) {
            if (y2 == y1) System.out.println(x1 + " " + y3);
            else if (y3 == y1) System.out.println(x1 + " " + y2);
        }
    }
}