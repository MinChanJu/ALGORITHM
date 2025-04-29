import java.io.*;
import java.util.*;

public class _12015_G2 {
  static List<Integer> A = new ArrayList<>();
  static List<Integer> LIS = new ArrayList<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    StringTokenizer st = new StringTokenizer(br.readLine());

    for (int i = 0; i < N; i++) {
      A.add(Integer.parseInt(st.nextToken()));
    }

    LIS.add(A.get(0));
    for (int i = 1; i < N; i++) {
      if (LIS.get(LIS.size() - 1) < A.get(i))
        LIS.add(A.get(i));
      else {
        int idx = binarySearch(A.get(i));
        LIS.set(idx, A.get(i));
      }
    }

    sb.append(LIS.size() + "\n");

    bw.write(sb.toString());
    bw.flush();
  }

  static int binarySearch(int key) {
    int s = 0, e = LIS.size() - 1;
    while (s <= e) {
      int mid = (s + e) / 2;
      if (LIS.get(mid) == key)
        return mid;
      else if (LIS.get(mid) > key)
        e = mid - 1;
      else if (LIS.get(mid) < key)
        s = mid + 1;
    }
    return s;
  }
}
