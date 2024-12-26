import java.io.*;

public class _2869_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp[] = br.readLine().split(" ");
        int A = Integer.parseInt(tmp[0]);
        int B = Integer.parseInt(tmp[1]);
        int V = Integer.parseInt(tmp[2]);
        System.out.println((V-B-1)/(A-B)+1);
    }
}