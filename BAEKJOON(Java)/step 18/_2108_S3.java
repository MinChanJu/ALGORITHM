import java.io.*;
import java.util.*;

public class _2108_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int num[] = new int[N];
        for (int i = 0; i < N; i++) num[i] = Integer.parseInt(br.readLine());
        Arrays.sort(num);

        System.out.printf("%d\n",Math.round(Arrays.stream(num).average().orElse(Double.NaN)));
        System.out.println(num[N/2]);

        Map<Integer, Integer> numcnt = new TreeMap<>();
        for (int i = 0; i < N; i++) numcnt.put(num[i], numcnt.getOrDefault(num[i], 0)+1);
        int maxvalue = 0;
        int maxc = 0;
        int k = 1;
        for (int i : numcnt.keySet()) {
            if (numcnt.get(i) > maxc) {
                maxc = numcnt.get(i);
                maxvalue = i;
                k = 1;
            } else if (numcnt.get(i) == maxc && k == 1) {
                maxvalue = i;
                k = 0;
            }
        }
        System.out.println(maxvalue);
        System.out.println(num[N-1]-num[0]);
    }
}