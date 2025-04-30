import java.io.*;
import java.util.*;

public class _1022_G3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    StringTokenizer st = new StringTokenizer(br.readLine());
    int r1 = Integer.parseInt(st.nextToken());
    int c1 = Integer.parseInt(st.nextToken());
    int r2 = Integer.parseInt(st.nextToken());
    int c2 = Integer.parseInt(st.nextToken());
    
    List<List<Integer>> storm = new ArrayList<>();
    for (int i = r1; i <= r2; i++) {
      List<Integer> ls = new ArrayList<>();
      for (int j = c1; j <= c2; j++) {
        if (Math.abs(i) > Math.abs(j)) {
          if (i < 0) ls.add(sigma(0, -i, 0, -1) - j);
          else ls.add(sigma(1, i+1, 1, -1) + j);
        }
        else {
          if (j < 0) ls.add(sigma(0,-j,0,1)+i);
          else ls.add(sigma(0,j,1,1)-i);
        }
        if (i == j && i > 0) ls.set(ls.size()-1, (2*i+1)*(2*i+1));
      }
      storm.add(ls);
    }

    int m = 0;
    for (List<Integer> list : storm) {
      for (Integer s : list) {
        if (m < String.valueOf(s).length()) m = String.valueOf(s).length();
      }
    }

    for (List<Integer> list : storm) {
      for (Integer s : list) {
        int k = m-String.valueOf(s).length();
        String gap = new String(new char[k]).replace('\0', ' ');
        sb.append(gap).append(s).append(" ");
      }
      sb.append("\n");
    }

    bw.write(sb.toString());
    bw.flush();
  }

  static int sigma(int s, int e, int even, int ch) {
    int sum = 1;
    for (int i = s; i < e; i++) {
      if (even != 0) sum += 4*2*i+ch;
      else sum += 4*2*i+4+ch;
    }
    return sum;
  }
}