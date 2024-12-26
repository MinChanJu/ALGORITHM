import java.io.*;

public class _14215_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String tmp[] = br.readLine().split(" ");
        int a = Integer.parseInt(tmp[0]);
        int b = Integer.parseInt(tmp[1]);
        int c = Integer.parseInt(tmp[2]);

        if (a+b+c-Math.max(Math.max(a,b),c) > Math.max(Math.max(a,b),c)) System.out.println(a+b+c);
        else System.out.println(2*(a+b+c-Math.max(Math.max(a,b),c))-1);
    
    }
}