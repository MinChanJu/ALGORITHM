import java.io.*;

public class _9935_G4 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringBuilder sb = new StringBuilder();

    String S = br.readLine();
    String tnt = br.readLine();
    char[] result = new char[S.length()];
    int idx = 0, tl = tnt.length();
    for (int i = 0; i < S.length(); i++) {
      result[idx++] = S.charAt(i);
      if (idx - tl < 0)
        continue;
      boolean flag = true;
      for (int j = 0; j < tl; j++) {
        if (result[idx - tl + j] != tnt.charAt(j)) {
          flag = false;
          break;
        }
      }
      if (flag) {
        idx -= tl;
      }
    }

    if (idx == 0)
      sb.append("FRULA\n");
    else
      sb.append(new String(result, 0, idx) + "\n");

    bw.write(sb.toString());
    bw.flush();
  }
}