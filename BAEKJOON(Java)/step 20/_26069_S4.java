import java.io.*;
import java.util.*;

public class _26069_S4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Map<String, Integer> infection = new HashMap<>();
        infection.put("ChongChong", 1);
        for (int i = 0; i < N; i++) {
            String tmp[] = br.readLine().split(" ");
            if (infection.containsKey(tmp[0]) && !infection.containsKey(tmp[1])) infection.put(tmp[1], 1);
            if (!infection.containsKey(tmp[0]) && infection.containsKey(tmp[1])) infection.put(tmp[0], 1);
        }

        System.out.println(infection.size());
    }
}