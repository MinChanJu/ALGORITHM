import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class _2480_B4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String dice = br.readLine();
        int a = Integer.parseInt(dice.split(" ")[0]);
        int b = Integer.parseInt(dice.split(" ")[1]);
        int c = Integer.parseInt(dice.split(" ")[2]);

        if (a == b && b == c) System.out.println(10000+1000*a);
        else if (a == b) System.out.println(1000+100*a);
        else if (a == c) System.out.println(1000+100*a);
        else if (b == c) System.out.println(1000+100*b);
        else if (a > b && a > c) System.out.println(100*a);
        else if (b > a && b > c) System.out.println(100*b);
        else if (c > a && c > b) System.out.println(100*c);
    }
}
