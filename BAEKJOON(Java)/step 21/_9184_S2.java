import java.io.*;
import java.util.*;

public class _9184_S2 {
    static Map<_9184_Pair, Integer> dp = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if (a == -1 && b == -1 && c == -1) break;
            sb.append(String.format("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c)));
        }

        bw.write(sb.toString());
        bw.flush();
    }

    static int w(int a, int b, int c) {
        if (dp.getOrDefault(new _9184_Pair(a,b,c), -1) != -1) return dp.get(new _9184_Pair(a,b,c));

        if (a <= 0 || b <= 0 || c <= 0) {
            dp.put(new _9184_Pair(a, b, c), 1);
            return dp.get(new _9184_Pair(a,b,c));
        }

        if (a > 20 || b > 20 || c > 20) {
            dp.put(new _9184_Pair(a, b, c), 1048576);
            return dp.get(new _9184_Pair(a,b,c));
        }

        if (a < b && b < c) {
            dp.put(new _9184_Pair(a, b, c), w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c));
            return dp.get(new _9184_Pair(a,b,c));
        }

        dp.put(new _9184_Pair(a, b, c), w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1));
        return dp.get(new _9184_Pair(a,b,c));
    }
}

class _9184_Pair {
    private final int a, b, c;

    public _9184_Pair(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public int getA() {
        return a;
    }

    public int getB() {
        return b;
    }

    public int getC() {
        return c;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        _9184_Pair Pair = (_9184_Pair) obj;
        return Objects.equals(a, Pair.a) && Objects.equals(b, Pair.b) && Objects.equals(c, Pair.c);
    }

    @Override
    public int hashCode() {
        return Objects.hash(a,b,c);
    }
}