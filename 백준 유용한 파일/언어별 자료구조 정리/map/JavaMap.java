import java.util.*;

public class JavaMap {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        map.put("null", 51);
        map.put("sfa", 21);
        map.put("gf", 324);
        map.put("sdaa", 129);
        map.put("aa", 14);

        if (map.getOrDefault("msf", 0) == 0) System.out.println("없음");

        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println("Key: " + entry.getKey() + "  Value: " + entry.getValue());
        }
    }
}
