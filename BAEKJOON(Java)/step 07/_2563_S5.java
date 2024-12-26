import java.io.*;

public class _2563_S5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int board[][] = new int[100][100];
        int N = Integer.parseInt(br.readLine());
        int a,b;
        String tmp[];
        for (int t = 0; t < N; t++) {
            tmp = br.readLine().split(" ");
            a = Integer.parseInt(tmp[0]);
            b = Integer.parseInt(tmp[1]);
            
            for (int i = a; i < a+10; i++) {
                for (int j = b; j < b+10; j++) {
                    board[i][j] = 1;
                }
            }
        }
        
        int sum = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                sum += board[i][j];
            }
        }

        System.out.println(sum);
    }
}
