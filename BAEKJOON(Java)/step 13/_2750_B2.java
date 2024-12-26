import java.io.*;
import java.util.*;

public class _2750_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Integer tmp[] = new Integer[N];

        for (int i = 0; i < N; i++) {
            tmp[i] = Integer.parseInt(br.readLine());
        }
        
        Arrays.sort(tmp);

        for (int i = 0; i < N; i++) {
            System.out.println(tmp[i]);
        }
    }
}