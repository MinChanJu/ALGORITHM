import java.io.*;
import java.util.*;

public class _11478_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        int size = input.length();
        Set<String> set = new HashSet<>();
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j <= size-i; j++) {
                set.add(input.substring(j, j+i));
            }
        }

        System.out.println(set.size());
    }
}