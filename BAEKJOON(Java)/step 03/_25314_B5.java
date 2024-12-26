import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class _25314_B5 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N/4; i++) {
            System.out.printf("long ");
        }
        System.out.println("int");
    }
}