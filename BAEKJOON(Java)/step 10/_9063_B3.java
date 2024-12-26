import java.io.*;

public class _9063_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int minX=10000, minY=10000, maxX=-10000, maxY=-10000;
        int N = Integer.parseInt(br.readLine());
        String tmp[];
        for (int i = 0; i < N; i++) {
            tmp = br.readLine().split(" ");
            int X = Integer.parseInt(tmp[0]);
            int Y = Integer.parseInt(tmp[1]);

            if (minX > X) minX = X;
            if (maxX < X) maxX = X;

            if (minY > Y) minY = Y;
            if (maxY < Y) maxY = Y;
        }

        System.out.println(((maxX-minX)*(maxY-minY)));
    }
}