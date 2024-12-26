import java.io.*;
import java.util.*;

public class _19532_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int f = Integer.parseInt(st.nextToken());

        int x, y;

        if (a == 0) {
            y = c/b;
            x = (f-e*y)/d;
        } else if (d == 0){
            y = f/e;
            x = (c-b*y)/a;
        } else if (b == 0) {
            x = c/a;
            y = (f-d*x)/e;
        } else if (e == 0) {
            x = f/d;
            y = (c-a*x)/b;
        } else {
            x = (c*e-f*b)/(a*e-d*b);
            y = (c-a*x)/b;
        }
        System.out.println(x + " " + y);
    }
}