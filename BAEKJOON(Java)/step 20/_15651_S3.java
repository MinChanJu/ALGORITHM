import java.io.*;
import java.util.*;

public class _15651_S3 {
    static int M;
    static int num[];
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        init(N);

        combi(0, new ArrayList<>());

        System.out.print(sb);

    }

    static void combi(int s, List<Integer> current) {
        if (current.size() == M) {
            for (Integer integer : current) {
                sb.append(integer).append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int i = 0; i < num.length; i++) {
            current.add(num[i]);
            combi(i+1, current);
            current.remove(current.size()-1);
        }
    }

    static void init(int n) {
        num = new int[n];
        for (int i = 0; i < n; i++) {
            num[i] = i+1;
        }
    }
}