import java.io.*;
import java.util.*;

public class _2580_G4 {
    static List<List<Integer>> sudoku = new ArrayList<>();
    static List<List<Integer>> fix = new ArrayList<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int i = 0; i < 9; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<Integer> tmp = new ArrayList<>();
            for (int j = 0; j < 9; j++) {
                int x = Integer.parseInt(st.nextToken());
                tmp.add(x);
                if (x == 0) {
                    List<Integer> p = new ArrayList<>();
                    p.add(i);
                    p.add(j);
                    fix.add(p);
                }
            }
            sudoku.add(tmp);
        }

        dfs(0);
    }

    static void dfs(int s) {
        if (s == fix.size()) {
            for (List<Integer> list : sudoku) {
                for (int i = 0; i < list.size(); i++) {
                    sb.append(list.get(i));
                    if (i != list.size()) sb.append(" ");
                }
                sb.append("\n");
            }
            System.out.print(sb);
            System.exit(0);
        }

        List<Integer> p = fix.get(s);

        for (int i = 1; i < 10; i++) {
            if (check_row(p.get(0), i) && check_col(p.get(1), i) && check_square(p.get(0), p.get(1), i)) {
                sudoku.get(p.get(0)).set(p.get(1), i);
                dfs(s+1);
                sudoku.get(p.get(0)).set(p.get(1), 0);
            }
        }
    }

    static boolean check_row(int r, int num) {
        return !sudoku.get(r).contains(num);
    }

    static boolean check_col(int c, int num) {
        for (List<Integer> list : sudoku) {
            if (list.get(c) == num) return false;
        }
        return true;
    }

    static boolean check_square(int r, int c, int num) {
        r /= 3;
        c /= 3;
        if (sudoku.get(r*3+0).get(3*c+0) == num) return false;
        if (sudoku.get(r*3+0).get(3*c+1) == num) return false;
        if (sudoku.get(r*3+0).get(3*c+2) == num) return false;
        if (sudoku.get(r*3+1).get(3*c+0) == num) return false;
        if (sudoku.get(r*3+1).get(3*c+1) == num) return false;
        if (sudoku.get(r*3+1).get(3*c+2) == num) return false;
        if (sudoku.get(r*3+2).get(3*c+0) == num) return false;
        if (sudoku.get(r*3+2).get(3*c+1) == num) return false;
        if (sudoku.get(r*3+2).get(3*c+2) == num) return false;
        return true;
    }
}
