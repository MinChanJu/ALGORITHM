import java.io.*;
import java.util.*;

public class _20920_S3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String tmp[] = br.readLine().split(" ");
        int N = Integer.parseInt(tmp[0]);
        int M = Integer.parseInt(tmp[1]);

        Map<String, Integer> wordcnt = new HashMap<>();
        LinkedList<String> wordbook = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            if (str.length() < M) continue;
            if (wordcnt.getOrDefault(str,0) == 0) wordbook.add(str);
            wordcnt.put(str,wordcnt.getOrDefault(str, 0)+1);
        }

        Collections.sort(wordbook, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                int cntComp = Integer.compare(wordcnt.get(s2), wordcnt.get(s1));
                if (cntComp != 0) return cntComp;

                int lengComp = Integer.compare(s2.length(), s1.length());
                if (lengComp != 0) return lengComp;

                return s1.compareTo(s2);
            }
        });

        bw.write(String.join("\n", wordbook)+"\n");
        bw.flush();
    }
}