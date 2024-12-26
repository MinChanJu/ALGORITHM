import java.io.*;

public class _2941_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp = br.readLine();
        String cro[] = new String[]{"dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="};
        for (String string : cro) {
            tmp = tmp.replace(string, ".");
        }
        System.out.println(tmp.length());
        // int total = 0;
        // int N = tmp.length();
        // int i = 0;
        // while (i < N) {
        //     if (i < N-2 && tmp.charAt(i) == 'd' && tmp.charAt(i+1) == 'z' && tmp.charAt(i+2) == '=') {
        //         total += 1; i += 3;
        //     } else if (i < N-1 && tmp.charAt(i) == 'd' && tmp.charAt(i+1) == '-') {
        //         total += 1; i += 2;
        //     } else if (i < N-1 && tmp.charAt(i) == 'c' && tmp.charAt(i+1) == '=') {
        //         total += 1; i += 2;
        //     } else if (i < N-1 && tmp.charAt(i) == 'c' && tmp.charAt(i+1) == '-') {
        //         total += 1; i += 2;
        //     } else if (i < N-1 && tmp.charAt(i) == 'l' && tmp.charAt(i+1) == 'j') {
        //         total += 1; i += 2;
        //     } else if (i < N-1 && tmp.charAt(i) == 'n' && tmp.charAt(i+1) == 'j') {
        //         total += 1; i += 2;
        //     } else if (i < N-1 && tmp.charAt(i) == 's' && tmp.charAt(i+1) == '=') {
        //         total += 1; i += 2;
        //     } else if (i < N-1 && tmp.charAt(i) == 'z' && tmp.charAt(i+1) == '=') {
        //         total += 1; i += 2;
        //     } else {
        //         total += 1; i++;
        //     }
        // }
        // System.out.println(total);
    }
}
