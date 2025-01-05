import java.util.*;

public class JavaSort {
    public static void main(String[] args) {
        // 정수
        System.out.println("정수\n-------------------------");

        List<Integer> oneArray = Arrays.asList(6, 3, 5, 2, 7, 9, 1, 4, 8);

        printOneArray(oneArray);
        oneArray.sort(null);
        printOneArray(oneArray);

        List<List<Integer>> twoArray = Arrays.asList(
            Arrays.asList(1, 4, 6),
            Arrays.asList(8, 3, 2),
            Arrays.asList(2, 5, 9)
        );

        printTwoArray(twoArray);
        twoArray.sort((a,b) -> a.get(1) - b.get(1));
        printTwoArray(twoArray);


        // 문자열
        System.out.println("문자열\n-------------------------");

        List<String> oneArrayStr = Arrays.asList("test", "als", "민찬", "djg", "car", "asfnd", "asfldnvladsd");

        printOneArray(oneArrayStr);
        oneArrayStr.sort((a, b) -> a.length() - b.length());
        printOneArray(oneArrayStr);

        List<List<String>> twoArrayStr = Arrays.asList(
            Arrays.asList("test", "alsaads", "민찬"),
            Arrays.asList("car", "dogsdf", "big"),
            Arrays.asList("hor", "sdka", "fgg")
        );

        printTwoArray(twoArrayStr);
        twoArrayStr.sort((a,b) -> {
            if (a.get(1).length() == b.get(1).length()) return a.get(1).compareTo(b.get(1));
            return a.get(1).length() - b.get(1).length();
        });
        printTwoArray(twoArrayStr);
    }

    static <T> void printOneArray(List<T> oneArray) {
        for (T element : oneArray) System.out.print(element + " ");
        System.out.println("\n-------------------------");
    }

    static <T> void printTwoArray(List<List<T>> twoArray) {
        for (List<T> row : twoArray) {
            for (T element : row) System.out.print(element + " ");
            System.out.println();
        }
        System.out.println("-------------------------");
    }
}
