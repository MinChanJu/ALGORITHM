import java.io.*;
import java.util.*;

public class _9663_G4 {
    static int cnt = 0;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        NQueen(0, new ArrayList<>());
        System.out.println(cnt);
    }

    static void NQueen(int s, List<Integer> rocate) {
        if (s == N) {
            cnt++;
            return;
        }

        for (int i = 0; i < N; i++) {
            boolean k = true;
            for (int j = 0; j < s; j++) {
                if (i == rocate.get(j) || s-j == i-rocate.get(j) || j-s == i-rocate.get(j)) {
                    k = false;
                    break;
                }
            }
            if (k) {
                rocate.add(i);
                NQueen(s+1, rocate);
                rocate.remove(s);
            }
        }
    }
}