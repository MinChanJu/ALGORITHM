import java.io.*;

public class _25083_B5 {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        sb.append("         ,r'\"7\n")
        .append("r`-_   ,'  ,/\n")
        .append(" \\. \". L_r'\n")
        .append("   `~\\/\n")
        .append("      |\n")
        .append("      |\n");
        bw.write(sb.toString());
        bw.flush();
    }
}