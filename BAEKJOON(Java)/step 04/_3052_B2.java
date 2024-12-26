import java.io.*;

public class _3052_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int map[] = new int[42];
        for (int i = 0; i < 10; i++) {
            int n = Integer.parseInt(br.readLine());
            map[n%42] = 1;
        }

        int total = 0;
        for (int i : map) {
            total += i;
        }

        System.out.println(total);
    }
}