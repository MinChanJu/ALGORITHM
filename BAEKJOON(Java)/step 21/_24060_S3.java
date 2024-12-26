import java.io.*;
import java.util.StringTokenizer;

public class _24060_S3 {
    static int K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int num[] = new int[N];
        for (int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }
        
        merge_sort(num, 0, N-1);
        if (K > 0) System.out.println(-1);
    }

    static void merge_sort(int A[], int p, int r) {
        if (p < r)  {
            int q = (p + r) / 2;
            merge_sort(A, p, q);
            merge_sort(A, q + 1, r);
            merge(A, p, q, r);
        }
    }
    
    static void merge(int A[], int p, int q, int r) {
        int i = p, j = q + 1, t = 0;
        int tmp[] = new int[r-p+1];
        while (i <= q && j <= r) {
            if (A[i] <= A[j]) tmp[t++] = A[i++];
            else tmp[t++] = A[j++];
        }

        while (i <= q) tmp[t++] = A[i++];
        while (j <= r) tmp[t++] = A[j++];

        i = p; t = 0;
        while (i <= r) {
            A[i++] = tmp[t++];
            if (--K == 0) {
                System.out.println(A[i-1]);
                System.exit(0);
            }
        }
    }
}