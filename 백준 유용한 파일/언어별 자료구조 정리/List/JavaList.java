import java.util.*;

public class JavaList {
    public static void main(String[] args) {
        List<Integer> array = new ArrayList<>();
        array.add(12);
        array.add(2);
        array.add(67);
        array.add(23);

        System.out.println(array.toString() + "\n");

        System.out.println("size : " + array.size());
        System.out.println("get(3) : " + array.get(3));
        System.out.println("isEmpty : " + array.isEmpty());
        System.out.println("equals : " + array.equals(List.of(12,2,67,23)));
        System.out.println("contains(3) : " + array.contains(3));
        System.out.println("contains(12) : " + array.contains(12));
        System.out.println("getFirst : " + array.getFirst());
        System.out.println("getLast : " + array.getLast());
        System.out.println("indexOf(67) : " + array.indexOf(67));

        array.remove(0);
        System.out.println(array.toString());
        array.remove(2);
        System.out.println(array.toString());
        array.remove(1);
        System.out.println(array.toString());

        array.clear();
        System.out.println("clear + isEmpty : " + array.isEmpty());

        List<Integer> arrayInit = Arrays.asList(2,4,1);
        System.out.println(arrayInit.toString());
    }
}
