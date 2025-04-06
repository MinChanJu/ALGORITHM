import java.io.*;
import java.util.*;

public class _14889_S1 {
    static int N;
    static int S[][];
    static int min = 100000000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        S = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                S[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        solve(0, 0,0, new int[N]);
        System.out.println(min);
    }

    static void solve(int start, int startTeam, int linkTeam, int A[]) {
        int sum = 0;
        for (int i = 0; i < start; i++) {
            sum += A[i];
        }

        if (sum == N/2) {
            for (int i = start; i < N; i++) {
                for (int j = 0; j < i; j++) {
                    if (A[j] == 0) linkTeam += S[i][j] + S[j][i];
                }
                A[i] = 0;
            }
            if (linkTeam > startTeam && min > linkTeam-startTeam) min = linkTeam-startTeam;
            if (linkTeam <= startTeam && min > startTeam-linkTeam) min = startTeam-linkTeam;
            return;
        } else if (start-sum == N/2) {
            for (int i = start; i < N; i++) {
                for (int j = 0; j < i; j++) {
                    if (A[j] == 1) startTeam += S[i][j] + S[j][i];
                }
                A[i] = 1;
            }
            if (linkTeam > startTeam && min > linkTeam-startTeam) min = linkTeam-startTeam;
            if (linkTeam <= startTeam && min > startTeam-linkTeam) min = startTeam-linkTeam;
            return;
        }

        int tmp[] = new int[N];
        int s = startTeam;
        int l = linkTeam;
        for (int i = 0; i < start; i++) {
            tmp[i] = A[i];
            if (A[i] == 1) s += S[start][i] + S[i][start];
            else l += S[start][i] + S[i][start];
        }
        tmp[start] = 1;
        solve(start+1, s, linkTeam, tmp);
        tmp[start] = 0;
        solve(start+1, startTeam, l, tmp);
    }
}