import java.io.*;
import java.util.*;

public class _2075_S3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    int N = Integer.parseInt(br.readLine());
    PriorityQueue<Integer> heap = new PriorityQueue<>(Comparator.reverseOrder());
    for (int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int j = 0; j < N; j++) {
        heap.add(Integer.parseInt(st.nextToken()));
      }
    }

    for (int i = 1; i < N; i++) {
      heap.poll();
    }

    bw.write(heap.poll() + "\n");
    bw.flush();
  }
}