import java.io.*;;

public class _1157_B1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cnt[] = new int[26];
        String tmp = br.readLine();
        for (char ch : tmp.toCharArray()) {
            if (ch >= 97) cnt[ch-97]++;
            else cnt[ch-65]++;
        }
        int max = 0;
        boolean pos = true;
        for (int i = 1; i < cnt.length; i++) {
            if (cnt[max] < cnt[i]) {
                max = i;
                pos = true;
            } else if (cnt[max] == cnt[i]) {
                pos = false;
            }
        }

        if (pos) System.out.println((char) (max+65));
        else System.out.println("?");
    }
}
