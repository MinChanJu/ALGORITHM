import java.io.*;
import java.util.*;

public class _25192_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Map<String, Integer> user = new HashMap<>();
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            if (tmp.equals("ENTER")) user = new HashMap<>();
            else if (!user.containsKey(tmp)) {
                cnt++;
                user.put(tmp, 1);
            }
        }
        System.out.println(cnt);
    }
}