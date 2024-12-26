import java.io.*;
import java.util.*;

public class _2587_B2 {
public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int tmp[] = new int[5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        tmp[i] = Integer.parseInt(br.readLine());
        sum += tmp[i];
    }
    Arrays.sort(tmp);
    System.out.println(sum/5);
    System.out.println(tmp[2]);
}
}