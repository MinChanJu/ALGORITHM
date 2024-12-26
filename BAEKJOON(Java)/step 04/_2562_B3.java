import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class _2562_B3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int max = 0;
        int index = 0;
        for (int i = 0; i < 9; i++) {
            int tmp = Integer.parseInt(br.readLine());
            if (max < tmp) {
                max = tmp;
                index = i+1;
            }
        }
        System.out.println(max);
        System.out.println(index);
    }
}