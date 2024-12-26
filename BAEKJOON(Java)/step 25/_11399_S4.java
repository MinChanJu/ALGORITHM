import java.io.*;
import java.util.*;

public class _11399_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int array[] = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) array[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(array);
        int sum = 0;
        for (int i = 0; i < array.length; i++) sum += array[i]*(N-i);

        System.out.println(sum);
    }
}
