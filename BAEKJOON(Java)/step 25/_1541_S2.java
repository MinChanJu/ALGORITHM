import java.io.*;

public class _1541_S2 {
    static String formula;
    static int idx = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        formula = br.readLine();
        int sum = 0, last = 0, s = 1;
        while (idx < formula.length()) {
            last += ReadInt();
            if (idx >= formula.length()) {
                if (s == 1) sum += last;
                else sum -= last;
                break;
            }
            if (formula.charAt(idx++) == '+') continue;
            else {
                if (s == 1) {
                    sum += last;
                    s = 0;

                }
                else sum -= last;
                last = 0;
            }
        }

        System.out.println(sum);
    }

    static int ReadInt() {
        int sum = 0;
        char now = formula.charAt(idx++);

        while (48 <= now && now <= 57) {
            sum = sum*10 + now-48;
            if (idx >= formula.length()) {
                idx++;
                break;
            }
            now = formula.charAt(idx++);
        }
        idx--;
        return sum;
    }
}
