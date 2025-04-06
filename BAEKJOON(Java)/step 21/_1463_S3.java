import java.io.*;
import java.util.*;

public class _1463_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int dp[] =  new int[N+1];
        LinkedList<Integer> queue = new LinkedList<>();
        queue.add(N);
        
        while (!queue.isEmpty()) {
            int node = queue.poll();
            if (node == 1) break;
            if (node%3 == 0 && dp[node/3] == 0) {
                dp[node/3] = dp[node] + 1;
                queue.add(node/3);
            }
            if (node%2 == 0 && dp[node/2] == 0) {
                dp[node/2] = dp[node] + 1;
                queue.add(node/2);
            }
            if (node-1 > 0 && dp[node-1] == 0) {
                dp[node-1] = dp[node] + 1;
                queue.add(node-1);
            }
        }

        System.out.println(dp[1]);
    }
}