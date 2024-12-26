import java.io.*;

public class _2745_B2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp[] = br.readLine().split(" ");

        char str[] = tmp[0].toCharArray();
        int B = Integer.parseInt(tmp[1]);
        long digit = 0;
        for (int i = str.length-1; i >= 0; i--) {
            if (str[i] >= 65) digit += (str[i]-55)*Math.pow(B, str.length-1-i);
            else digit += (str[i]-48)*Math.pow(B, str.length-1-i);
        }

        System.out.println(digit);
    }
}