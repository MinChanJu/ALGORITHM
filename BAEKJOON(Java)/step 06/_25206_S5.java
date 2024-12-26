import java.io.*;

public class _25206_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double sum = 0;
        double total = 0;
        String tmp[];
        for (int i = 0; i < 20; i++) {
            tmp = br.readLine().split(" ");
            if (tmp[2].equals("P")) continue;
            sum += Double.parseDouble(tmp[1]);
            total += Double.parseDouble(tmp[1])*score(tmp[2]);
        }
        System.out.println(total/sum);
    }

    static Double score(String hak) {
        if (hak.equals("A+")) return 4.5;
        else if (hak.equals("A0")) return 4.0;
        else if (hak.equals("B+")) return 3.5;
        else if (hak.equals("B0")) return 3.0;
        else if (hak.equals("C+")) return 2.5;
        else if (hak.equals("C0")) return 2.0;
        else if (hak.equals("D+")) return 1.5;
        else if (hak.equals("D0")) return 1.0;
        else if (hak.equals("F")) return 0.0;
        else return 0.0;
    }
}