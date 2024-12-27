import java.util.*;

public class JavaSort {
    public static void main(String[] args) {
        int oneArray[] = { 6, 3, 5, 2, 7, 9, 1, 4, 8 };

        printOneArray(oneArray);
        Arrays.sort(oneArray);
        printOneArray(oneArray);

        int twoArray[][] = { { 1, 4, 6 }, { 8, 3, 2 }, { 2, 5, 9 } };

        printTwoArray(twoArray);
        Arrays.sort(twoArray, (a,b) -> {return a[2] - b[2];});
        printTwoArray(twoArray);

        String oneArrayStr[] = { "tefdsb", "fkfn", "Bdsk", "asf", "yssnf" };

        printOneArrayStr(oneArrayStr);
        Arrays.sort(oneArrayStr, (a, b) -> {
            if (a.length() == b.length()) {
                for (int i = 0; i < a.length(); i++) {
                    if (a.charAt(i) != b.charAt(i)) return a.charAt(i) - b.charAt(i);
                }
            }
            return a.length()-b.length();
        });
        printOneArrayStr(oneArrayStr);
    }

    static void printOneArray(int oneArray[]) {
        for (int i : oneArray) System.out.print(i + " ");
        System.out.println();
    }

    static void printTwoArray(int twoArray[][]) {
        System.out.println("-------------------------");
        for (int[] row : twoArray) {
            for (int i : row) System.out.print(i + " ");
            System.out.println();
        }
        System.out.println("-------------------------");
    }

    static void printOneArrayStr(String oneArrayStr[]) {
        for (String str : oneArrayStr) System.out.print(str + " ");
        System.out.println();
    }
}
