import java.io.*;

public class _24313_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp[] = br.readLine().split(" ");
        int a1 = Integer.parseInt(tmp[0]);
        int a0 = Integer.parseInt(tmp[1]);
        int c = Integer.parseInt(br.readLine());
        int n0 = Integer.parseInt(br.readLine());
        a1 -= c;
        if (a1 > 0) System.out.println(0);
        else if (a1 == 0 && a0 <= 0) System.out.println(1);
        else if (a1 == 0) System.out.println(0);
        else if (a1*n0+a0 <= 0) System.out.println(1);
        else System.out.println(0);
    }
}