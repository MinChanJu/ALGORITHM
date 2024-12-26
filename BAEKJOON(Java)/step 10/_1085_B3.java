import java.io.*;
import java.util.StringTokenizer;

public class _1085_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        int xmin = Math.min(x, (w-x));
        int ymin = Math.min(y, (h-y));
        System.out.println(Math.min(xmin,ymin));
    }
}