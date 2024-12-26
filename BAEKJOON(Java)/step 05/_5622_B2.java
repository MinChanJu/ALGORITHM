import java.io.*;

public class _5622_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        int total = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'A' || S.charAt(i) == 'B' || S.charAt(i) == 'C') total += 3;
            else if (S.charAt(i) == 'D' || S.charAt(i) == 'E' || S.charAt(i) == 'F') total += 4;
            else if (S.charAt(i) == 'G' || S.charAt(i) == 'H' || S.charAt(i) == 'I') total += 5;
            else if (S.charAt(i) == 'J' || S.charAt(i) == 'K' || S.charAt(i) == 'L') total += 6;
            else if (S.charAt(i) == 'M' || S.charAt(i) == 'N' || S.charAt(i) == 'O') total += 7;
            else if (S.charAt(i) == 'P' || S.charAt(i) == 'Q' || S.charAt(i) == 'R' || S.charAt(i) == 'S' ) total += 8;
            else if (S.charAt(i) == 'T' || S.charAt(i) == 'U' || S.charAt(i) == 'V') total += 9;
            else if (S.charAt(i) == 'W' || S.charAt(i) == 'X' || S.charAt(i) == 'Y' || S.charAt(i) == 'Z' ) total += 10;
        }

        System.out.println(total);
    }
}
